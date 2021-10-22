/**
*  \file
*
*  \brief       Omc StdDiag Interface
*
*  This file contains the interface definition for the Omc StdDiag
*  Adapter.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2016
*
*  \version     5.1.0
*
*/
/*
   MISRA-C:2004 Rule 19.1: including Omc_MemMap.h is necessary throughout
   the file according to memory abstraction. See PRQA 5087.
*/

#ifndef OMC_STDDIAGADAPTER_H
#define OMC_STDDIAGADAPTER_H

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/

#include "Omc_Version.h"
#include "Omc_Cfg.h"
#include "Omc_Data.h"
#include "BUtil/PlatformTypes.h"   /* BMW standard types                        */

#ifdef __cplusplus
extern "C" {
#endif
/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* Check version of the module */
#if (!Omc_CHECK_VERSION(5, 1, 0))
#error "Version of Omc_StdDiagAdapter.h does not match the version of the module!"
#endif

/*------------------------------------------------------------------------------
                      Data Types
------------------------------------------------------------------------------*/
typedef enum {
  OMC_STDDIAG_OK,
  OMC_STDDIAG_RUNNING,
  OMC_STDDIAG_NOT_OK
} Omc_StdDiag_ResultType;

/*------------------------------------------------------------------------------
                      Global Variables
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Global Constants
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Global Function Declarations
------------------------------------------------------------------------------*/

#define Omc_START_SEC_CODE
#include "Omc_MemMap.h" /* PRQA S 5087 */

extern Omc_StdDiag_ResultType Omc_StdDiag_AllowOpModeChange(
    Omc_GenericOperatingModeType ActiveOperatingMode, Omc_GenericExtendedOperatingModeType ActiveExtendedOperatingMode,
    Omc_GenericOperatingModeType NewOperatingMode, Omc_GenericExtendedOperatingModeType NewExtendedOperatingMode);

extern Omc_StdDiag_ResultType Omc_StdDiag_OpModeSwitchCancelled(
    Omc_GenericOperatingModeType ActiveOperatingMode, Omc_GenericExtendedOperatingModeType ActiveExtendedOperatingMode,
    Omc_GenericOperatingModeType NewOperatingMode, Omc_GenericExtendedOperatingModeType NewExtendedOperatingMode);

#define Omc_STOP_SEC_CODE
#include "Omc_MemMap.h" /* PRQA S 5087 */

#ifdef __cplusplus
}
#endif

#endif /* OMC_STDDIAGADAPTER_H */
