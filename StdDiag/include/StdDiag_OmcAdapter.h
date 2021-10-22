/**
*  \file
*
*  \brief       BMW SWC StdDiag
*
*  This file is the Omc adapter header file of the generic part of the module StdDiag
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

#ifndef STDDIAG_OMCADAPTER_H
#define STDDIAG_OMCADAPTER_H

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
#error "Version of StdDiag_OmcAdapter.h does not match the version of the module!"
#endif

#define STDDIAG_OMC_MODE_NORMAL    0u
#define STDDIAG_OMC_MODE_ASSEMBLY  1u
#define STDDIAG_OMC_MODE_TRANSPORT 2u
#define STDDIAG_OMC_MODE_BMW_FLASH 3u

#define STDDIAG_OMC_MODE_EXTENSION_NORMAL 0u
#define STDDIAG_OMC_MODE_EXTENSION_1      1u

/*------------------------------------------------------------------------------
                      Data Types
-------------------------------------------------------------------------------*/

typedef uint8 StdDiag_Omc_OperatingModeType;

typedef uint8 StdDiag_Omc_ExtendedOperatingModeType;

#ifdef __cplusplus
extern "C" {
#endif
/*------------------------------------------------------------------------------
                      Extern Declarations
-------------------------------------------------------------------------------*/

/**
 * \brief This function returns the current operating mode
 *
 * \retval StdDiag_Omc_OperatingModeType current operating mode
 *
 */
extern StdDiag_Omc_OperatingModeType StdDiag_Omc_GetCurrentOperatingMode(void);


/**
 * \brief This function returns the current extended operating mode
 *
 * \retval StdDiag_Omc_ExtendedOperatingModeType current extended operating mode
 *
 */
extern StdDiag_Omc_ExtendedOperatingModeType StdDiag_Omc_GetCurrentExtendedOperatingMode(void);

#ifdef __cplusplus
}
#endif

#endif /* STDDIAG_OMCADAPTER_H */


