/**
*  \file
*
*  \brief       BMW SWC StdDiag
*
*  This file is the Darh adapter header file of the generic part of the module StdDiag
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

#ifndef STDDIAG_DARHADAPTER_H
#define STDDIAG_DARHADAPTER_H

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "BUtil/PlatformTypes.h"
#include "StdDiag_Version.h"

/*------------------------------------------------------------------------------
                      Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!StdDiag_CHECK_VERSION(5,3,0))
#error "Version of StdDiag_DarhAdapter.h does not match the version of the module!"
#endif

#ifdef __cplusplus
extern "C" {
#endif
/*------------------------------------------------------------------------------
                      Extern Declarations
-------------------------------------------------------------------------------*/

/**
 * \brief This function returns the current RoE state
 *
 * \retval uint8 the current RoE state
 *
 */
extern uint8 StdDiag_Darh_GetRoeState(void);

#ifdef __cplusplus
}
#endif

#endif /* STDDIAG_DARHADAPTER_H */


