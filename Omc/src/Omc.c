/**
*  \file
*
*  \brief       BMW SWC Omc
*
*  Source Code for Omc containing API and internal
*  functions
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.1.0
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
#include "Omc_Version.h"                      /* Omc version check */
#include "Omc_Data.h"                         /* Omc NvM RAM mirror */
#include "Omc.h"                              /* Omc API */
#include "Omc_Cfg.h"                          /* Omc configuration */
#include "Omc_Assert.h"                       /* Omc developement errors */
#include "Omc_ApplAdapter.h"                  /* API provided by adapter */
#include "Omc_StdDiagAdapter.h"               /* API provided by adapter */
#include "Omc_ConcAdapter.h"                  /* API provided by adapter */
#include "Omc_MgmtAdapter.h"                  /* API provided by adapter */
#include "Omc_NvMAdapter.h"                   /* API provided by adapter */
#include "Omc_UDSAdapter.h"                   /* API provided by adapter */
#include "Omc_ErrMemAdapter.h"                /* API provided by adapter */

#include "BUtil/PlatformTypes.h"                /* BMW standard types */
#include <stddef.h>

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/
/* Check version of the module */
#if (!Omc_CHECK_VERSION(5, 1, 0))
#error "Version of Omc.c does not match the version of the module!"
#endif

/*------------------------------------------------------------------------------
                      Global Variables
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Global Constants
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Local Data Types
------------------------------------------------------------------------------*/
/** \brief Omc State Machine
 */
typedef enum {
  /* Init state, i.e. not yet initialized. When initialized, Omc switches to Omc_ST_IDLE */
      Omc_ST_INIT,
  /* Idle state */
      Omc_ST_IDLE,
  /* call stddiag to ask for allowance */
      Omc_ST_CALL_STDDIAG,
  /* waiting for stddiag to complete the processing */
      Omc_ST_WAIT_STDDIAG,
  /* waiting for staddiag to confirm the cancellation */
      Omc_ST_CANCEL_STDDIAG,
#if (OMC_OPMODECALLOUT == STD_ON)
  /* call the applicaion to ask for allowance */
      Omc_ST_CALL_APPLICATION,
  /* waiting for appliction to complete the processing */
      Omc_ST_WAIT_APPLICATION,
#endif
  /* waiting for application to confirm the cancellation */
      Omc_ST_CANCEL_APPLICATION,
  /* the Mode change is allowed by the stddiag and the application */
      Omc_ST_CHANGEALLOWED,
  /* waiting the NVM to complete the write */
      Omc_ST_WAITNVM
} Omc_StateType;

typedef struct {
  boolean cancelApplication;
  UDS_ErrorCodeType retVal;
} Omc_CancelType;



/*------------------------------------------------------------------------------
                      Local Variables
------------------------------------------------------------------------------*/

#define Omc_START_SEC_VAR_INIT_UNSPECIFIED
#include "Omc_MemMap.h" /* PRQA S 5087 */

static volatile Omc_StateType Omc_State = Omc_ST_INIT;

#define Omc_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Omc_MemMap.h" /* PRQA S 5087 */


#define Omc_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Omc_MemMap.h" /* PRQA S 5087 */

static Omc_NvDataType Omc_RequestedData;

/* The following variable may be used in only one function if OMC_OPMODECALLOUT is disabled. In those cases
 * we devaite of misra Rule 8.7. To keep the code readability we use always a static variable and not a function
 * static variable */
/* PRQA S 3218 1 */
static Omc_CancelType Omc_Cancel;

#define Omc_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Omc_MemMap.h" /* PRQA S 5087 */

/*------------------------------------------------------------------------------
                      Local Constants
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Local Function Prototypes
------------------------------------------------------------------------------*/

#define Omc_START_SEC_CODE
#include "Omc_MemMap.h" /* PRQA S 5087 */

static ErrMem_ResultType Omc_SetErrorStatus(Omc_GenericOperatingModeType OperatingMode);

static ErrMem_ResultType Omc_SetErrorMemoryLock(Omc_GenericOperatingModeType OperatingMode);

static void Omc_WriteOperatingModes_Callback(NvMService_ResultType result, void* context);

static UDS_ReturnType Omc_ChangeOperatingMode(UDS_ErrorCodeType* UDS_ErrorCode);

static void Omc_CancelStdDiag(boolean cancelApplication, UDS_ErrorCodeType errorCode);

#if (OMC_OPMODECALLOUT == STD_ON)
static void Omc_CancelApplication(void);
#endif

#define Omc_STOP_SEC_CODE
#include "Omc_MemMap.h" /* PRQA S 5087 */

/*------------------------------------------------------------------------------
                      Local Functions
------------------------------------------------------------------------------*/

#define Omc_START_SEC_CODE
#include "Omc_MemMap.h" /* PRQA S 5087 */

/**
 * \brief This callback is called by the NvM after the complation of a write operation.
 *
 * \param[in] result result of the write operation
 * \param[in] context a context, this parameter is not used
 *
 * \remark The following Nvm Callback API is part of the BPS adapter standard, the ptr context may be not used
 *         and therefore set as const, but not in all cases. Therefore  no const is added to the signature
 */
/* PRQA S 3673 1 */
static void Omc_WriteOperatingModes_Callback(NvMService_ResultType result, void* context) {
  /* The paramter context is used as boolean in Omc. The interface is defined within BPS Adapters Guide as
   * pointer. The following cast is intentionally and correct. */
  /* PRQA S 0306 1 */
  boolean isOpMode = (boolean) (size_t) context;

  if (Omc_ST_WAITNVM == Omc_State) {
    if (NVMSERVICE_OK == result) {
      /* complete the mode change copying the mode to the Omc_NvData variable */
      Omc_NvData = Omc_RequestedData;

      /* enable or disable the enable condition */
      (void) Omc_SetErrorMemoryLock(Omc_RequestedData.operatingMode);

      /* inform the users about the new mode */
      (void) Omc_Mgmt_ProvideOperatingMode(Omc_RequestedData.operatingMode);
      (void) Omc_Mgmt_ProvideExtendedOperatingMode(Omc_RequestedData.extendedOperatingMode);

      /* set the mode event to failed or passed */
      (void) Omc_SetErrorStatus(Omc_RequestedData.operatingMode);

      if (TRUE == isOpMode) {
        Omc_UDS_RoutineControlOperatingMode_Start_ResultOk();
      } else {
        Omc_UDS_RoutineControlExtendedOperatingMode_Start_ResultOk();
      }

      /* set the status back to idle to accept the next service */
      Omc_State = Omc_ST_IDLE;
    } else {


      Omc_CancelStdDiag(
#if (OMC_OPMODECALLOUT == STD_ON)
          TRUE,
#else
          FALSE,
#endif
          UDS_DIAG_E_GENERALPROGRAMMINGFAILURE);

    }
  }
}

/**
 * \brief This function informs StdDiag to inform that a mode change has been cancelled.
 *
 * \param[in] cancelApplication if TRUE after informing the StdDiag the application shall also be informed.
 * \param[in] errorCode error code returned over diagnostic after informing StdDiag and (if also required)
 *            the application.
 *
 * \remarks The StdDiag may confirm the cancellation immediately or return RUNNING and inform later Omc over the
 *          callback Omc_StdDiagCbk_OpModeSwitchCancelledAck.
 *
 */
static void Omc_CancelStdDiag(boolean cancelApplication, UDS_ErrorCodeType errorCode) {
  Omc_StdDiag_ResultType retVal;
  Omc_Cancel.cancelApplication = cancelApplication;
  Omc_Cancel.retVal = errorCode;
  Omc_State = Omc_ST_CANCEL_STDDIAG;

  retVal = Omc_StdDiag_OpModeSwitchCancelled(
      Omc_NvData.operatingMode, Omc_NvData.extendedOperatingMode, Omc_RequestedData.operatingMode,
      Omc_RequestedData.extendedOperatingMode);

  switch (retVal) {
    case OMC_STDDIAG_RUNNING:
      /* waiting for stddiag cancelation to be acknoledge */
      /* state Omc_State already set to Omc_ST_CANCEL_STDDIAG */
      break;

    case OMC_STDDIAG_OK:
    case OMC_STDDIAG_NOT_OK:
    default:
#if (OMC_OPMODECALLOUT == STD_ON)
      if (TRUE == Omc_Cancel.cancelApplication) {
        Omc_CancelApplication();
      } else {
#endif /* #if (OMC_OPMODECALLOUT == STD_ON) */
        if (Omc_RequestedData.operatingMode != Omc_NvData.operatingMode) {
          Omc_UDS_RoutineControlOperatingMode_Start_ResultError(Omc_Cancel.retVal);
        } else {
          Omc_UDS_RoutineControlExtendedOperatingMode_Start_ResultError(Omc_Cancel.retVal);
        }
        Omc_State = Omc_ST_IDLE;
#if (OMC_OPMODECALLOUT == STD_ON)
      }
#endif /* #if (OMC_OPMODECALLOUT == STD_ON) */
      break;
  }
}

#if (OMC_OPMODECALLOUT == STD_ON)
/**
 * \brief This function informs the Application to inform that a mode change has been cancelled.
 *
 * \remarks The Application may confirm the cancellation immediately or return RUNNING and inform later Omc over the
 *          callback Omc_ApplicationCbk_OpModeSwitchCancelledAck.
 */
static void Omc_CancelApplication(void) {
  Omc_Appl_ResultType retVal;

  if (Omc_ST_CANCEL_STDDIAG == Omc_State) {
    /* state is set here and not if OMC_APPLICATION_RUNNING to avoid any race condition */
    Omc_State = Omc_ST_CANCEL_APPLICATION;

    retVal = Omc_Appl_OpModeSwitchCancelled(
        Omc_NvData.operatingMode, Omc_NvData.extendedOperatingMode, Omc_RequestedData.operatingMode,
        Omc_RequestedData.extendedOperatingMode);

    switch (retVal) {
      case OMC_APPL_RUNNING:
        /* waiting for application cancelation to be acknoledge */
        /* state Omc_State already set to Omc_ST_CANCEL_APPLICATION */
        break;

      case OMC_APPL_NOT_OK:
      case OMC_APPL_OK:
      default:
        if (Omc_RequestedData.operatingMode != Omc_NvData.operatingMode) {
          Omc_UDS_RoutineControlOperatingMode_Start_ResultError(Omc_Cancel.retVal);
        } else {
          Omc_UDS_RoutineControlExtendedOperatingMode_Start_ResultError(Omc_Cancel.retVal);
        }
        Omc_State = Omc_ST_IDLE;
        break;
    }
  }
}
#endif

/**
 * \brief This function performs the change of an oprating or extended operating mode
 *
 * \param[out] UDS_ErrorCode contains the UDS error code, only written if the returned value contains
 *             UDS_DIAG_JOB_FINISHED_E_NOT_OK
 *
 * \retval UDS_DIAG_JOB_FINISHED_E_NOT_OK: if an error occurred
 *         UDS_DIAG_JOB_RUNNING: if the NvM has been called and the callback has to be waited.
 *
 */
static UDS_ReturnType Omc_ChangeOperatingMode(UDS_ErrorCodeType* UDS_ErrorCode) {
  UDS_ReturnType retVal = UDS_DIAG_JOB_FINISHED_OK;
  boolean isOpModeChanged;

  Omc_StdDiag_ResultType stdDiagRetVal;
#if (OMC_OPMODECALLOUT == STD_ON)
  Omc_Appl_ResultType applRetVal;
#endif

  /* used to run the state machine again if needed. */
  boolean runAgain;

  do {
    /* disable the run again flag */
    runAgain = FALSE;

    switch (Omc_State) {
      case Omc_ST_CALL_STDDIAG:
        /* to avoid any race condition Omc_State is set to Omc_ST_WAIT_STDDIAG;*/
        Omc_State = Omc_ST_WAIT_STDDIAG;

        /* check allowance of StdDiag to perform the mode change. The extended mode is set to normal as any request
         * to change the op mode reset the extended mode to normal */
        stdDiagRetVal = Omc_StdDiag_AllowOpModeChange(
            Omc_NvData.operatingMode, Omc_NvData.extendedOperatingMode, Omc_RequestedData.operatingMode,
            Omc_RequestedData.extendedOperatingMode);

        switch (stdDiagRetVal) {
          case OMC_STDDIAG_RUNNING:
            /* Omc_State already set to Omc_ST_WAIT_STDDIAG */

            retVal = UDS_DIAG_JOB_RUNNING;
            break;

          case OMC_STDDIAG_OK:
#if (OMC_OPMODECALLOUT == STD_ON)
            Omc_State = Omc_ST_CALL_APPLICATION;
#else
            Omc_State = Omc_ST_CHANGEALLOWED;
#endif
            runAgain = TRUE;
            break;

          case OMC_STDDIAG_NOT_OK:
          default:
            *UDS_ErrorCode = UDS_DIAG_E_CONDITIONSNOTCORRECT;
            retVal = UDS_DIAG_JOB_FINISHED_E_NOT_OK;
            Omc_State = Omc_ST_IDLE;
            break;
        }
        break;

#if (OMC_OPMODECALLOUT == STD_ON)
      case Omc_ST_CALL_APPLICATION:
        /* to avoid a race condition Omc_State is set to Omc_ST_WAIT_APPLICATION */
        Omc_State = Omc_ST_WAIT_APPLICATION;
        /* check allowance of the Application to perform the mode change. The extended mode is set to normal as any
         * request to change the op mode reset the extended mode to normal */
        applRetVal = Omc_Appl_AllowOpModeChange(
            Omc_NvData.operatingMode, Omc_NvData.extendedOperatingMode, Omc_RequestedData.operatingMode,
            Omc_RequestedData.extendedOperatingMode);

        switch (applRetVal) {
          case OMC_APPL_RUNNING:
            /* Omc_State already set to Omc_ST_WAIT_APPLICATION */
            retVal = UDS_DIAG_JOB_RUNNING;
            break;

          case OMC_APPL_OK:
            Omc_State = Omc_ST_CHANGEALLOWED;
            runAgain = TRUE;
            break;

          case OMC_APPL_NOT_OK:
          default:
            Omc_CancelStdDiag(FALSE, UDS_DIAG_E_CONDITIONSNOTCORRECT);
            retVal = UDS_DIAG_JOB_RUNNING;
            break;
        }
        break;
#endif /* #if ( OMC_OPMODECALLOUT == STD_ON ) */

      case Omc_ST_CHANGEALLOWED:
        Omc_State = Omc_ST_WAITNVM;
        isOpModeChanged = (boolean) (Omc_RequestedData.operatingMode != Omc_NvData.operatingMode);

        /* if the mode change is allowed the first task to do is to store the new mode
         * in NvM */
        /** \lhref DK_T3_702, DK_T3_743, FZM_SC_SYS_PA_169, FZM_SC_SYS_PA_329 */
        /* In the last parameter of API Omc_NvM_WriteOperatingModes (context) a boolean value is stored within a
         * pointer */ /* PRQA S 0306 3 */
        if (NVMSERVICE_NOT_OK ==
            Omc_NvM_WriteOperatingModes(
                &Omc_RequestedData, &Omc_WriteOperatingModes_Callback, (void*) (size_t) isOpModeChanged)) {
          Omc_CancelStdDiag(
#if (OMC_OPMODECALLOUT == STD_ON)
              TRUE,
#else /* #if ( OMC_OPMODECALLOUT == STD_ON ) */
              FALSE,
#endif /* #if ( OMC_OPMODECALLOUT == STD_ON ) */
              UDS_DIAG_E_GENERALPROGRAMMINGFAILURE);
        }
        retVal = UDS_DIAG_JOB_RUNNING;
        break;

        /* still busy or uninitialized, no new request is possible */
      default: {
        *UDS_ErrorCode = UDS_DIAG_E_CONDITIONSNOTCORRECT;
        retVal = UDS_DIAG_JOB_FINISHED_E_NOT_OK;
        break;
      }
    }
  } while (TRUE == runAgain);

  return retVal;
}

/**
 * \brief This function sets the error status depnding on OperatingMode
 *
 * \param[in] OperatingMode operating mode for error status
 *
 * \retval ERRMEMSERVICE_OK: on success
 *         ERRMEMSERVICE_NOT_OK: on error
 *
 */
static ErrMem_ResultType Omc_SetErrorStatus(Omc_GenericOperatingModeType OperatingMode) {
  ErrMem_ResultType result;
  ErrMem_EventStatusType errorStatus;
  ErrMem_ClearEventAllowedType clearAllowed;
  if (OperatingMode == OMC_GENMODE_NORMAL) {
    /** \lhref DK_T3_1254 */
    errorStatus = ERRMEM_EVENT_STATUS_PASSED;
    clearAllowed = ERRMEM_CLEAR_ALLOWED;
  } else {
    /** \lhref DK_T3_717, DK_T3_749 */
    errorStatus = ERRMEM_EVENT_STATUS_FAILED;
    clearAllowed = ERRMEM_CLEAR_NOT_ALLOWED;
  }
  (void) Omc_ErrMem_SetClearEventAllowedOmcOpMode(clearAllowed);
  result = Omc_ErrMem_SetErrorStatusOmcOpMode(errorStatus);
  return result;
}

/**
 * \brief This function sets the error memory lock depnding on OperatingMode
 *
 * \param[in] OperatingMode operating mode for error memory lock
 *
 * \retval ERRMEMSERVICE_OK: if success
 *         ERRMEMSERVICE_NOT_OK: if an error occurrs
 *
 */
static ErrMem_ResultType Omc_SetErrorMemoryLock(Omc_GenericOperatingModeType OperatingMode) {
  ErrMem_ResultType result;
  /* Set condion to TRUE resp. FALSE. */
  /** \lhref DK_T3_706 */
  if (OperatingMode == OMC_GENMODE_NORMAL) {
    result = Omc_ErrMem_DisableMemoryLockOmcOpMode();
  } else {
    result = Omc_ErrMem_EnableMemoryLockOmcOpMode();
  }
  return result;
}

#define Omc_STOP_SEC_CODE
#include "Omc_MemMap.h" /* PRQA S 5087 */

/*------------------------------------------------------------------------------
                      Global Functions
------------------------------------------------------------------------------*/

#define Omc_START_SEC_CODE
#include "Omc_MemMap.h" /* PRQA S 5087 */

/**
 * \brief This function initializes Omc
 *
 */
void Omc_Init(void) {
  Omc_State = Omc_ST_INIT;

  /* Notify users of the OperatingMode */
  (void) Omc_Mgmt_ProvideOperatingMode(Omc_NvData.operatingMode);

  /* Notify users of the ExtendedOperatingMode */
  (void) Omc_Mgmt_ProvideExtendedOperatingMode(Omc_NvData.extendedOperatingMode);

  /* Set Error Memory Lock with appropriate value. */
  (void) Omc_SetErrorMemoryLock(Omc_NvData.operatingMode);

  /* Set Error Status with appropriate value. */
  (void) Omc_SetErrorStatus(Omc_NvData.operatingMode);

  Omc_State = Omc_ST_IDLE;
}

/**
 * \brief This function is called cyclically to set the current event status and the correct state of the enable
 *        conditon.
 *
 */
void Omc_CycleTask(void) {
  Omc_NvDataType stateType;

  Omc_CritSect_Mode_Enter();

  if (Omc_ST_IDLE == Omc_State) {
    /* get the current mode before leaving the critical section
     * to ensure correct set of the enable condition and event */
    stateType = Omc_NvData;

    Omc_CritSect_Mode_Exit();

    /* Set Error Memory Lock with appropriate value. */
    (void) Omc_SetErrorMemoryLock(stateType.operatingMode);

    /* Set Error Status with appropriate value. */
    /** \lhref DK_T3_707, DK_T3_1480 */
    (void) Omc_SetErrorStatus(stateType.operatingMode);
  } else {
    Omc_CritSect_Mode_Exit();
  }
}

/**
 * \brief This function is called on start of UDS routine control to change the OperatingMode. It checks if change
 *        is allowed and triggers the writing of the new Mode to NvM.
 *
 * \param[in] OperatingMode the new requested operating mode
 * \param[out] UDS_ErrorCode UDS error code only set if the return value is set to  UDS_DIAG_JOB_FINISHED_E_NOT_OK
 *
 * \retval UDS_DIAG_JOB_FINISHED_OK: if sucess
 *         UDS_DIAG_JOB_RUNNING: if the job is still running
 *         UDS_DIAG_JOB_FINISHED_E_NOT_OK: if an error occurrs, error will be indicated in the output parameter
 *                                         UDS_ErrorCode
 *
 * \lhref DK_T3_720, DK_T3_725, DK_T3_727, DK_T3_729, DK_T3_733
 */
UDS_ReturnType
Omc_RoutineControlOperatingMode_Start(Omc_GenericOperatingModeType OperatingMode, UDS_ErrorCodeType* UDS_ErrorCode) {
  UDS_ReturnType retVal = UDS_DIAG_JOB_FINISHED_OK;

  /* local variable to indicate if a call to change op mode is necesarry. This variable is needed be able to call
   * a function after leaving the critical section */
  boolean callChangeOpMode = FALSE;

  Omc_CritSect_Mode_Enter();

  switch (Omc_State) {

    case Omc_ST_IDLE:
      /* idle, new request is possible */
      /* check if reuquested mode is a new one */
      if (OperatingMode == Omc_NvData.operatingMode) {
        /* current mode has been requested, nothing to do */
        retVal = UDS_DIAG_JOB_FINISHED_OK;
      } else if (OMC_GENMODE_BMW_FLASH < OperatingMode) {
        /* check if request is in range */
        *UDS_ErrorCode = UDS_DIAG_E_REQUESTOUTOFRANGE;
        retVal = UDS_DIAG_JOB_FINISHED_E_NOT_OK;
      } else {
        Omc_State = Omc_ST_CALL_STDDIAG; /* next step is to check StdDiag */

        /* requested mode */
        Omc_RequestedData.operatingMode = OperatingMode;
        /* changing the op mode also force the extended mode to be reset to OMC_GENMODE_EXTENSION_NORMAL */
        /** \lhref DK_T3_748, DK_T3_767, FZM_SC_SYS_PA_337 */
        Omc_RequestedData.extendedOperatingMode = OMC_GENMODE_EXTENSION_NORMAL;

        callChangeOpMode = TRUE;
      }
      break;

      /* still busy or uninitialized, no new request is possible */
    default: {
      *UDS_ErrorCode = UDS_DIAG_E_CONDITIONSNOTCORRECT;
      retVal = UDS_DIAG_JOB_FINISHED_E_NOT_OK;
      break;
    }
  }

  Omc_CritSect_Mode_Exit();

  if (TRUE == callChangeOpMode) {
    retVal = Omc_ChangeOperatingMode(UDS_ErrorCode);
  }

  return retVal;
}

/**
 * \brief This function is called on start of UDS routine control to change the ExtendedOperatingMode. It checks
 *        if change is allowed and triggers the writing of the new Mode to NvM.
 *
 * \param[in] ExtendedOperatingMode the new requested extended operating mode
 * \param[out] UDS_ErrorCode UDS error code only set if the return value is set to  UDS_DIAG_JOB_FINISHED_E_NOT_OK
 *
 * \retval UDS_DIAG_JOB_FINISHED_OK: if sucess
 *         UDS_DIAG_JOB_RUNNING: if the job is still running
 *         UDS_DIAG_JOB_FINISHED_E_NOT_OK: if an error occurrs, error will be indicated in the output parameter
 *                                         UDS_ErrorCode
 *
 */
UDS_ReturnType Omc_RoutineControlExtendedOperatingMode_Start(
    Omc_GenericExtendedOperatingModeType ExtendedOperatingMode, UDS_ErrorCodeType* UDS_ErrorCode) {

  UDS_ReturnType retVal = UDS_DIAG_JOB_FINISHED_OK;

  /* local variable to indicate if a call to change op mode is necesarry. This variable is needed be able to call
   * a function after leaving the critical section */
  boolean callChangeOpMode = FALSE;

  Omc_CritSect_Mode_Enter();

  switch (Omc_State) {
    case Omc_ST_IDLE:
      /* idle, new request is possible */
      /* check if reuquested mode is a new one */
      if (ExtendedOperatingMode == Omc_NvData.extendedOperatingMode) {
        /* current mode has been requested, nothing to do */
        retVal = UDS_DIAG_JOB_FINISHED_OK;
      } else if ((OMC_GENMODE_EXTENSION_SAVE_ENERGY < ExtendedOperatingMode) &&
                 (OMC_GENMODE_EXTENSION_INVALID != ExtendedOperatingMode)) {
        /** lhref DK_T3_754 */
        /* check if new requested value is in range */
        *UDS_ErrorCode = UDS_DIAG_E_REQUESTOUTOFRANGE;
        retVal = UDS_DIAG_JOB_FINISHED_E_NOT_OK;
      } else if (OMC_GENMODE_NORMAL == Omc_NvData.operatingMode) {
        /* changing the extended mode to != normal mode is not allowed
         * in the normal mode */
        /** \lhref DK_T3_748 */
        *UDS_ErrorCode = UDS_DIAG_E_CONDITIONSNOTCORRECT;
        retVal = UDS_DIAG_JOB_FINISHED_E_NOT_OK;
      } else {
        Omc_State = Omc_ST_CALL_STDDIAG; /* next step is to check StdDiag */

        /* copy current operating mode */
        Omc_RequestedData.operatingMode = Omc_NvData.operatingMode;
        /* requested extended mode */
        Omc_RequestedData.extendedOperatingMode = ExtendedOperatingMode;

        callChangeOpMode = TRUE;
      }
      break;

      /* still busy or uninitialized, no new request is possible */
    default: {
      *UDS_ErrorCode = UDS_DIAG_E_CONDITIONSNOTCORRECT;
      retVal = UDS_DIAG_JOB_FINISHED_E_NOT_OK;
      break;
    }
  }

  Omc_CritSect_Mode_Exit();

  if (TRUE == callChangeOpMode) {
    retVal = Omc_ChangeOperatingMode(UDS_ErrorCode);
  }

  return retVal;
}

/**
 * \brief This function writes the actual operating mode, if Omc is already initialized, otherwise it returns an error
 *
 * \param[out] OperatingMode Omc Operating Mode, this parameter is only set if the function returns
 *                           UDS_DIAG_JOB_FINISHED_OK
 * \param[out] UDS_ErrorCode UDS error code, only set if the return value is UDS_DIAG_JOB_FINISHED_E_NOT_OK
 *
 * \retval UDS_DIAG_JOB_FINISHED_E_NOT_OK: if an error occurred, error is set in UDS_ErrorCode
 *         UDS_DIAG_JOB_FINISHED_OK: if success, operation mode is set to OperatingMode
 *
 * \lhref DK_T3_1255, DK_T3_736, DK_T3_738, DK_T3_740
 *
 */
UDS_ReturnType
Omc_ReadDataOperatingMode(Omc_GenericOperatingModeType* OperatingMode, UDS_ErrorCodeType* UDS_ErrorCode) {
  UDS_ReturnType retVal;

  Omc_CritSect_Mode_Enter();

  if (Omc_ST_IDLE != Omc_State) {
    *UDS_ErrorCode = UDS_DIAG_E_CONDITIONSNOTCORRECT;
    retVal = UDS_DIAG_JOB_FINISHED_E_NOT_OK;
  } else {
    *OperatingMode = Omc_NvData.operatingMode;
    retVal = UDS_DIAG_JOB_FINISHED_OK;
  }

  Omc_CritSect_Mode_Exit();

  return retVal;
}

/**
 * \brief This function writes the actual extended operating mode, if Omc is already initialized,
 * otherwise it returns an error
 *
 * \param[out] ExtendedOperatingMode Omc Extended Operating Mode, this parameter is only set if the function returns
 *                                   UDS_DIAG_JOB_FINISHED_OK
 * \param[out] UDS_ErrorCode UDS error code, only set if the return value is UDS_DIAG_JOB_FINISHED_E_NOT_OK
 *
 * \retval UDS_DIAG_JOB_FINISHED_E_NOT_OK: if an error occurred, error is set in UDS_ErrorCode
 *         UDS_DIAG_JOB_FINISHED_OK: if success, operation mode is set to ExtendedOperatingMode
 *
 * \lhref DK_T3_1255
 *
 */
UDS_ReturnType Omc_ReadDataExtendedOperatingMode(
    Omc_GenericExtendedOperatingModeType* ExtendedOperatingMode, UDS_ErrorCodeType* UDS_ErrorCode) {

  UDS_ReturnType retVal;

  Omc_CritSect_Mode_Enter();

  if (Omc_ST_IDLE != Omc_State) {
    *UDS_ErrorCode = UDS_DIAG_E_CONDITIONSNOTCORRECT;
    retVal = UDS_DIAG_JOB_FINISHED_E_NOT_OK;
  } else {
    *ExtendedOperatingMode = Omc_NvData.extendedOperatingMode;
    retVal = UDS_DIAG_JOB_FINISHED_OK;
  }

  Omc_CritSect_Mode_Exit();

  return retVal;
}

/**
 * \brief This callback is called by StdDiag to inform the completion of a mode switch check.
 *
 * \param[in] Result indicate with true if a mode change is allowed by StdDiag or not.
 *
 * \remark This API shall be called by StdDiag only if StdDiag returns RUNNING during the call
 *         Omc_StdDiag_AllowOpModeChange to indicate the completion of the change checks.
 *
 */
void Omc_StdDiagCbk_OpModeSwitchAllowedResult(boolean Result) {
  UDS_ErrorCodeType dummyErrorCode;
  if (Omc_ST_WAIT_STDDIAG == Omc_State) {
    if (TRUE == Result) {
#if (OMC_OPMODECALLOUT == STD_ON)
      Omc_State = Omc_ST_CALL_APPLICATION;
#else
      Omc_State = Omc_ST_CHANGEALLOWED;
#endif
      /* continue the execution of the state machine. Returned value and errorCode can be ignored, in
       * Omc_ST_CALL_APPLICATION or Omc_ST_CHANGEALLOWED only running can be returned.
       */
      (void) Omc_ChangeOperatingMode(&dummyErrorCode);
      (void) dummyErrorCode;
    } else {
      if (Omc_RequestedData.operatingMode != Omc_NvData.operatingMode) {
        Omc_UDS_RoutineControlOperatingMode_Start_ResultError(UDS_DIAG_E_CONDITIONSNOTCORRECT);
      } else {
        Omc_UDS_RoutineControlExtendedOperatingMode_Start_ResultError(UDS_DIAG_E_CONDITIONSNOTCORRECT);
      }
      Omc_State = Omc_ST_IDLE;
    }
  }
}

/**
 * \brief This callback is called by StdDiag to inform the completion of a mode change cancellation.
 *
 * \remark This API shall be called by StdDiag only if the StdDiag returns RUNNING during the call
 *         Omc_StdDiag_OpModeSwitchCancelled to indicate the completion of the cancellation.
 *
 */
void Omc_StdDiagCbk_OpModeSwitchCancelledAck(void) {
  if (Omc_ST_CANCEL_STDDIAG == Omc_State) {
#if (OMC_OPMODECALLOUT == STD_ON)
    if (TRUE == Omc_Cancel.cancelApplication) {
      Omc_CancelApplication();
    } else {
#endif
    if (Omc_RequestedData.operatingMode != Omc_NvData.operatingMode) {
      Omc_UDS_RoutineControlOperatingMode_Start_ResultError(Omc_Cancel.retVal);
    } else {
      Omc_UDS_RoutineControlExtendedOperatingMode_Start_ResultError(Omc_Cancel.retVal);
    }

    Omc_State = Omc_ST_IDLE;
#if (OMC_OPMODECALLOUT == STD_ON)
    }
#endif
  }
}

#if (OMC_OPMODECALLOUT == STD_ON)
/**
 * \brief This callback is called by the Application to inform the completion of a mode switch check.
 *
 * \param[in] Result indicate with true if a mode change is allowed by the Application or not.
 *
 * \remark This API shall be called by the Application only if the Application returns RUNNING during the call
 *         Omc_Application_AllowOpModeChange to indicate the completion of the change checks.
 *
 */
void Omc_ApplicationCbk_OpModeSwitchAllowedResult(boolean Result) {
  if (Omc_ST_WAIT_APPLICATION == Omc_State) {
    if (TRUE == Result) {
      Omc_State = Omc_ST_CHANGEALLOWED;
    } else {
    Omc_CancelStdDiag(FALSE, UDS_DIAG_E_CONDITIONSNOTCORRECT);
    }
  }
}
#endif

#if (OMC_OPMODECALLOUT == STD_ON)
/**
 * \brief This callback is called by the Application to inform the completion of a mode change cancellation.
 *
 * \remark This API shall be called by the Application only if the Application returns RUNNING during the call
 *         Omc_Appl_OpModeSwitchCancelled to indicate the completion of the cancellation.
 *
 */
void Omc_ApplicationCbk_OpModeSwitchCancelledAck(void) {
  if (Omc_ST_CANCEL_APPLICATION == Omc_State) {
    if (Omc_RequestedData.operatingMode != Omc_NvData.operatingMode) {
      Omc_UDS_RoutineControlOperatingMode_Start_ResultError(Omc_Cancel.retVal);
    } else {
      Omc_UDS_RoutineControlExtendedOperatingMode_Start_ResultError(Omc_Cancel.retVal);
    }
    Omc_State = Omc_ST_IDLE;
  }
}
#endif

#define Omc_STOP_SEC_CODE
#include "Omc_MemMap.h" /* PRQA S 5087 */
