/**
*  \file
*
*  \brief       BMW SWC StdDiag
*
*  This file is the application adapter header file of the generic part of the module StdDiag
*  for usage in the BMW AUTOSAR Core.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.3.0
*
*  \remarks     The StdDiag module is responsible for BMW specific session
*               handling and handles a number of BMW specific diagnostic requests.
*
*/

#ifndef STDDIAG_APPADAPTER_H
#define STDDIAG_APPADAPTER_H

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "StdDiag_Version.h"
#include "BUtil/PlatformTypes.h"
#include "BUtil/GenericUDSTypes.h"
#include "StdDiag_Cfg.h"
#include <string.h>

/*------------------------------------------------------------------------------
                      Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!StdDiag_CHECK_VERSION(5,3,0))
#error "Version of StdDiag_AppAdapter.h does not match the version of the module!"
#endif

/*------------------------------------------------------------------------------
                      Data Types
-------------------------------------------------------------------------------*/

typedef enum {
  /** application callout has been successfully finished -> means positive (UDS) response */
  STDDIAG_APPL_OK = 0U,
  /** application callout has been finished with Error -> means negative (UDS) response */
  STDDIAG_APPL_E_NOT_OK = 1U,
  /** application callout has not been finished - still running */
  STDDIAG_APPL_RUNNING = 2U
}StdDiag_App_ReturnType;


#ifdef __cplusplus
extern "C" {
#endif
/*------------------------------------------------------------------------------
                      Extern Declarations
-------------------------------------------------------------------------------*/

#if( STDDIAG_USRPRECONDITIONCHECK == STD_ON )
/**
 * \brief This function checks the current programming preconditions
 *
 * \param[in]  skipOnboardData indicates whether checking of bus dependent preconditions shall be skipped
 * \param[out] numberFailedPreconditions holds the number of failed preconditions
 * \param[out] failedPreconditionList holds a list of failed preconditions
 *
 * \retval STDDIAG_APPL_OK synchronous precondition check was successfull
 * \retval STDDIAG_APPL_RUNNING asynchronous precondition check was successfully started
 * \retval STDDIAG_APPL_E_NOT_OK precondition check failed
 */
extern StdDiag_App_ReturnType StdDiag_App_CheckProgrammingPreconditions(boolean skipOnboardData, size_t* numberFailedPreconditions, uint8* failedPreconditionList);

#endif /* STDDIAG_USRPRECONDITIONCHECK == STD_ON */

#if( STDDIAG_USER_ESTABLISH_INTRINSIC_SAFETY == STD_ON )
/**
 * \brief This function shall establish intrinsic safety
 *
 * This function is called during diagnostic job 0x31 01 0F 0C 03 (SetEnergyMode = Flash)
 * and shall establish intrinsic safety, i.e. backup data, prevent activation of failsafe mode,
 * set hardware to a safe condition. If one of these steps was not successful, all steps
 * shall be reverted.
 *
 * \retval STDDIAG_APPL_OK intrinsic safety is established
 * \retval STDDIAG_APPL_RUNNING asynchronous establishing of intrinsic safety was successfully started
 * \retval STDDIAG_APPL_E_NOT_OK intrinsic safety is not established
 *
 */
extern StdDiag_App_ReturnType StdDiag_App_EstablishIntrinsicSafety(void);

/**
 * \brief This function shall revert intrinsic safety
 *
 * This function is called during diagnostic job 0x31 01 0F 0C 00 (SetEnergyMode = Normal) if
 * flash mode was enabled before, and shall revert all actions done before during establishing
 * of intrinsic safety.
 *
 * \retval STDDIAG_APPL_OK intrinsic safety is reverted
 * \retval STDDIAG_APPL_RUNNING asynchronous reverting of intrinsic safety was successfully started
 * \retval STDDIAG_APPL_E_NOT_OK intrinsic safety is not reverted
 *
 */
extern StdDiag_App_ReturnType StdDiag_App_RevertIntrinsicSafety(void);

#endif /* STDDIAG_USER_ESTABLISH_INTRINSIC_SAFETY == STD_ON */

#if( STDDIAG_USER_ACTIVE_SESSION_STATE == STD_ON )
/**
 * \brief This function optionally sets active session state value
 *
 * This function is called during diagnostic job 0x22 F1 00 (Read Active Session State)
 * and allows an application to set the current active session state value, which is returned in the
 * second byte of the diagnostic response. If the application does not need to set this value for the
 * currently active diagnostic session, it shall return FALSE. Otherwise it shall write the new value
 * to the parameter activeSessionState and return TRUE.
 *
 * \param[in]  currentActiveSession indicates the currently active diagnostic session
 * \param[out] activeSessionState holds the new active session state value
 *
 * \retval TRUE new active session state value has been set
 * \retval FALSE active session state value has not been set
 *
 */
extern boolean StdDiag_App_GetActiveSessionState(UDS_SessionType currentActiveSession, uint8* activeSessionState);
#endif


#ifdef __cplusplus
}
#endif

#endif /* STDDIAG_APPADAPTER_H */



