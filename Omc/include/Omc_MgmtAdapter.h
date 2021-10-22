/**
*  \file
*
*  \brief       Omc Mgmt Interface
*
*  This file contains the interface definition for the Omc Management
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.1.0
*
*/

#ifndef OMC_MGMTADAPTER_H
#define OMC_MGMTADAPTER_H

/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/
/*
   MISRA-C:2004 Rule 19.1: including Omc_MemMap.h is necessary throughout
   the file according to memory abstraction. See PRQA 5087.
*/

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/

#include "Omc_Version.h"
#include "Omc_Data.h"

#ifdef __cplusplus
extern "C" {
#endif
/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* Check version of the module */
#if (!Omc_CHECK_VERSION(5,1,0))
   #error "Version of Omc_MgmtAdapter.h does not match the version of the module!"
#endif

/*------------------------------------------------------------------------------
                      Data Types
------------------------------------------------------------------------------*/

typedef enum {
   MGMTSERVICE_OK,
   MGMTSERVICE_NOT_OK
} MgmtService_ResultType;

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

extern MgmtService_ResultType Omc_Mgmt_ProvideOperatingMode(Omc_GenericOperatingModeType Mode);

extern MgmtService_ResultType Omc_Mgmt_ProvideExtendedOperatingMode(Omc_GenericExtendedOperatingModeType extendedMode);

#define Omc_STOP_SEC_CODE
#include "Omc_MemMap.h" /* PRQA S 5087 */

#ifdef __cplusplus
}
#endif

#endif /* OMC_MGMTADAPTER_H */

/*--- End of file ------------------------------------------------------------*/
