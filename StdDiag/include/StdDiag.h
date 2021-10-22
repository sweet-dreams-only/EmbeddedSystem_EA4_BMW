/**
*  \file
*
*  \brief       BMW SWC StdDiag
*
*  This file is the main header file of the generic part of the module StdDiag
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

#ifndef STDDIAG_H
#define STDDIAG_H

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "StdDiag_Version.h"
#include "StdDiag_Cfg.h"
#include "StdDiag_UDSAdapter.h"
#include "StdDiag_AppAdapter.h"
#include <string.h>

/*------------------------------------------------------------------------------
                      Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!StdDiag_CHECK_VERSION(5,3,0))
#error "Version of StdDiag.h does not match the version of the module!"
#endif

/*------------------------------------------------------------------------------
                      Data Types
-------------------------------------------------------------------------------*/
typedef uint8 StdDiag_ActiveSessionStateType[4];


#ifdef __cplusplus
extern "C" {
#endif
/*------------------------------------------------------------------------------
                      Extern Declarations
-------------------------------------------------------------------------------*/
extern void StdDiag_Init( void );

extern void StdDiag_Stop( void );

extern UDS_ReturnType StdDiag_ReadDataActiveSessionState(
    StdDiag_ActiveSessionStateType* activeSessionState,
    UDS_ErrorCodeType* errorCode);

extern UDS_ReturnType StdDiag_RoutineControlRawCheckProgrammingPreconditions_Start(
    const uint8* requestData,
    size_t reqDataLength,
    uint8* responseData,
    size_t *resDataLength,
    UDS_ErrorCodeType* errorCode );

extern UDS_ReturnType StdDiag_DiagRequest_Indication(
    uint8 serviceId,
    const uint8* requestData,
    uint16 dataSize,
    uint16 sourceAddress,
    UDS_ErrorCodeType* errorCode );

extern void StdDiag_DiagRequest_Confirmation(
    uint8 serviceId,
    uint16 sourceAddress,
    UDS_ConfirmationType confirmation );

extern void StdDiag_NotifyDefaultSessionEnter(void);

extern StdDiag_App_ReturnType StdDiag_AllowOpModeSwitch(
    uint8 currentOpMode,
    uint8 currentExtOpMode,
    uint8 newOpMode,
    uint8 newExtOpMode);

extern StdDiag_App_ReturnType StdDiag_OpModeSwitchCancelled(
    uint8 currentOpMode,
    uint8 currentExtOpMode,
    uint8 requestedOpMode,
    uint8 requestedExtOpMode);

#if( STDDIAG_IDRL_SUPPORT == STD_ON )
extern UDS_ReturnType StdDiag_ReadDataRawDIDTable(
    uint8* responseData,
    size_t* dataLength,
    UDS_ErrorCodeType* errorCode);
#endif /* (STDDIAG_IDRL_SUPPORT == STD_ON) */

#if( STDDIAG_USRPRECONDITIONCHECK == STD_ON )
extern void StdDiag_CheckProgrammingPreconditions_Callback_ResultOk(
    uint8* responseData,
    size_t resDataLength);

extern void StdDiag_CheckProgrammingPreconditions_Callback_ResultError(
    UDS_ErrorCodeType errorCode);
#endif /* STDDIAG_USRPRECONDITIONCHECK == STD_ON */


#ifdef __cplusplus
}
#endif

#endif /* STDDIAG_H */
