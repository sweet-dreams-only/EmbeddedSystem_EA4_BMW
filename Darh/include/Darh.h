/**
*  \file
*
*  \brief       BMW SWC Darh
*
*  This file contains the declarations of the BMW SWC Darh.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015
*
*  \version     5.1.0
*
*/
#ifndef DARH_H
#define DARH_H

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/
#include "BUtil/PlatformTypes.h"
#include "Darh_Version.h"               /* Own version header file */
#include "Darh_NvM.h"
#include "Darh_ErrMemAdapter.h"

#ifdef __cplusplus
extern "C" {
#endif
/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/
/* check version of the module */
#if (!Darh_CHECK_VERSION(5, 1, 0))
#error "Version of Darh.h does not match the version of the module!"
#endif

/**
 * \brief Indicates maximum number of transmitted events
 *
 * \lhref DMA_PA_5841
 */
#define DARH_MAX_TRANSMITTED                                               0x03U

/*--------------------[Instance ID]-------------------------------------------*/
/**
 * \brief Instance id of Darh
 */
#define DARH_INSTANCE_ID                                                   0x00U

/*------------------[API service IDs]-----------------------------------------*/
/**
 * \brief Darh_SetRoeSuspended() service id
 */
#define DARH_SID_SETROESUSPENDED                                           0x01U
/**
 * \brief Darh_EventDataChanged() service id
 */
#define DARH_SID_EVENTDATACHANGED                                          0x03U
/**
 * \brief Darh_QueueHandler() service id
 */
#define DARH_SID_QUEUEHANDLER                                              0x05U
/**
 * \brief Darh_ConditionCheckReadErrorQueueHandler() service id
 */
#define DARH_SID_CONDITIONCHECKREADERRORQUEUE                              0x06U
/**
 * \brief Darh_ReadErrorQueueLength() service id
 */
#define DARH_SID_READERRORQUEUELENGTH                                      0x07U
/**
 * \brief Darh_ReadErrorQueueHandler() service id
 */
#define DARH_SID_READERRORQUEUEDATA                                        0x08U
/**
 * \brief Darh_RoeManufacturerIndicationHandler() service id
 */
#define DARH_SID_MANUFACTURERINDICATION                                    0x09U
/**
 * \brief Darh_ConditionCheckReadActivelyReportedDtcHandler() service id
 */
#define DARH_SID_CONDITIONCHECKREADACTIVELYREPORTEDDTC                     0x0AU
/**
 * \brief Darh_ReadActivelyReportedDtcHandler() service id
 */
#define DARH_SID_READACTIVELYREPORTEDDTC                                   0x0BU
/**
 * \brief Darh_ReadActivelyReportedDtcLengthHandler() service id
 */
#define DARH_SID_READACTIVELYREPORTEDDTCLENGTH                             0x0CU
/**
 * \brief Darh_StartRoutineTriggerDtcHandler() service id
 */
#define DARH_SID_STARTROUTINETRIGGERDTC                                    0x0DU
/**
 * \brief Darh_ConditionCheckReadRoeStateHandler() service id
 */
#define DARH_SID_CONDITIONCHECKREADROESTATE                                0x10U
/**
 * \brief Darh_ReadDataRoeStateHandler() service id
 */
#define DARH_SID_READDATAROESTATE                                          0x11U

/*------------------[Development error codes]---------------------------------*/
/**
 * \brief Error code for use of Darh prior to initialization
 */
#define DARH_E_UNINIT                                                      0x02U
/**
 * \brief Error code for wrong function parameter
 */
#define DARH_E_PARAM                                                       0x01U

/*------------------------------------------------------------------------------
                      Data Types
------------------------------------------------------------------------------*/
/**
 * \brief Type used to store the internal state of the Darh Module.
 */
typedef struct {
  boolean running;        /** <= indicates with true if the Darh is running */
  boolean suspended;      /** <= indicates if Diagnose Master transmission is suspended */
} Darh_StateType;

/*------------------------------------------------------------------------------
                      Global Variables
------------------------------------------------------------------------------*/
#define Darh_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Darh_MemMap.h"

/**
 * \brief Stores the internal state of the Darh Module.
 */
extern Darh_StateType Darh_State;

#define Darh_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Darh_MemMap.h"

/*------------------------------------------------------------------------------
                      Global Function Declarations
------------------------------------------------------------------------------*/
#define Darh_START_SEC_CODE
#include "Darh_MemMap.h"

/**
 * \brief Description of function Darh_Init
 *
 * Performs the initialization of Darh Module.
 *
 * \param[in] --
 *
 * \return --
 *
 */
extern void Darh_Init(void);

/**
 * \brief Description of function Darh_Shutdown
 *
 * Performs the de-initialization of Darh Module.
 *
 * \param[in] --
 *
 * \return --
 *
 */
extern void Darh_Shutdown(void);

/**
 * \brief Description of function Darh_SetRoeSuspended
 *
 * Controls the current DARH ROE state.
 *
 * \param[in] suspended TRUE - ROE is suspended
 *                      FALSE - ROE is un-suspended
 *
 * \return boolean TRUE if success and FALSE in other case
 *
 */
extern boolean Darh_SetRoeSuspended(boolean suspended);

/**
 * \brief Description of function Darh_EventDataChanged
 *
 * Triggered by Error Manager in case event data has changed. In case this function is
 * called, although Darh has not been initialized a Development Assertion
 * indicating DARH_E_UNINIT is triggerd.
 *
 * \param[in] EventId ID of the event whose data changed
 *
 * \return --
 *
 */
extern void Darh_EventDataChanged(ErrMemService_EventIdType EventId);

/**
 * \brief Description of function Darh_GetRoeState
 *
 * Function is called by StdDiag to get the current Roe State.
 *
 * \global Darh_CurrentRoeState
 *
 * \param[out] DiagnoseMasterEnable 0 if transmission disable, 1 if enable. This parameter is only valid if TRUE is
 *             returned
 *
 * \return TRUE if success, false in other case. The out parameter DiagnoseMasterEnable is only valid if the function
 *         returns TRUE.
 *
 */
extern boolean Darh_GetRoeState(boolean* diagnoseMasterEnable);

#define Darh_STOP_SEC_CODE
#include "Darh_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* DARH_H */
