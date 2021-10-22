/**
*  \file
*
*  \brief       BMW SWC StdDiag
*
*  This file is the Stm adapter header file of the generic part of the module StdDiag
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

#ifndef STDDIAG_STMADAPTER_H
#define STDDIAG_STMADAPTER_H

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
#error "Version of StdDiag_StmAdapter.h does not match the version of the module!"
#endif

/*------------------------------------------------------------------------------
                      Data Types
-------------------------------------------------------------------------------*/

typedef enum {
  STDDIAG_STM_MODE_NON_PAD,
  STDDIAG_STM_MODE_PAD,
  STDDIAG_STM_MODE_UNAVAILABLE
}StdDiag_Stm_VehicleStateType;

#ifdef __cplusplus
extern "C" {
#endif
/*------------------------------------------------------------------------------
                      Extern Declarations
-------------------------------------------------------------------------------*/

/**
 * \brief This function returns the current vehicle state
 *
 * \retval STDDIAG_STM_MODE_PAD vehicle state is Pruefen_Analyse_Diagnose (PAD)
 * \retval STDDIAG_STM_MODE_NON_PAD vehicle state is other than PAD
 * \retval STDDIAG_STM_MODE_UNAVAILABLE vehicle state is not available or invalid
 *
 */
extern StdDiag_Stm_VehicleStateType StdDiag_Stm_GetVehicleState(void);

#ifdef __cplusplus
}
#endif

#endif /* STDDIAG_STMADAPTER_H */


