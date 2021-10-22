/**
*  \file
*
*  \brief       BMW SWC StdDiag
*
*  This file is the internal header file of the generic part of the module StdDiag
*  for usage in the BMW AUTOSAR Core.
*
*  \project     BMW Platform Software

*  \copyright   BMW AG 2017
*
*  \version     5.3.0
*
*  \remarks     The StdDiag module is responsible for BMW specific session
*               handling and handles a number of BMW specific diagnostic requests.
*
*/

#ifndef STDDIAG_INTERNAL_H
#define STDDIAG_INTERNAL_H

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "StdDiag_Version.h"

/*------------------------------------------------------------------------------
                      Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!StdDiag_CHECK_VERSION(5,3,0))
   #error "Version of StdDiag_Internal.h does not match the version of the module!"
#endif

/*------------------------------------------------------------------------------
                      Extern Declarations
-------------------------------------------------------------------------------*/
extern boolean StdDiag_IsInitialized(void);

#endif /* STDDIAG_INTERNAL_H */

