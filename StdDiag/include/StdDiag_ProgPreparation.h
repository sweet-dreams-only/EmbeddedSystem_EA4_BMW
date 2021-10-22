/**
*  \file
*
*  \brief       BMW SWC StdDiag
*
*  This file is an internal header file of the module StdDiag
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

#ifndef STDDIAG_PROGPREPARATION_H
#define STDDIAG_PROGPREPARATION_H

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "BUtil/PlatformTypes.h"
#include "StdDiag_Version.h"
#include "StdDiag_AppAdapter.h"

/*------------------------------------------------------------------------------
                      Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!StdDiag_CHECK_VERSION(5,3,0))
#error "Version of StdDiag_ProgPreparation.h does not match the version of the module!"
#endif


/*------------------------------------------------------------------------------
                      Data Types
-------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Extern Declarations
-------------------------------------------------------------------------------*/

extern void StdDiag_StateMachineInit( void );

extern void StdDiag_StateMachineStop( void );

extern uint8 StdDiag_GetActiveSessionState( void );

extern boolean StdDiag_IsPWFPreconditionValid( void );

extern boolean StdDiag_IsNDCDisabled( void );

#endif /* STDDIAG_PROGPREPARATION_H */
