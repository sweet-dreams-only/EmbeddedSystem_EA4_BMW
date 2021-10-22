/**
*  \file
*
*  \brief       BMW SWC StdDiag
*
*  This file is the management adapter header file of the generic part of the module StdDiag
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

#ifndef STDDIAG_MGMTADAPTER_H
#define STDDIAG_MGMTADAPTER_H

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "BUtil/PlatformTypes.h"
#include "StdDiag_Version.h"
#include <string.h>

/*------------------------------------------------------------------------------
                      Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!StdDiag_CHECK_VERSION(5,3,0))
#error "Version of StdDiag_MgmtAdapter.h does not match the version of the module!"
#endif

#ifdef __cplusplus
extern "C" {
#endif
/*------------------------------------------------------------------------------
                      Extern Declarations
-------------------------------------------------------------------------------*/

/**
 * \brief This function shall enable non diagnostic communication
 *
 */
extern void StdDiag_Mgmt_EnableNonDiagnosticCommunication(void);

/**
 * \brief This function shall disable non diagnostic communication
 *
 */
extern void StdDiag_Mgmt_DisableNonDiagnosticCommunication(void);

#ifdef __cplusplus
}
#endif

#endif /* STDDIAG_MGMTADAPTER_H */



