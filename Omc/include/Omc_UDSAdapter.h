/**
*  \file
*
*  \brief       Omc UDS Interface
*
*  This file contains the interface definition for the Omc UDS Adapter.
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

#ifndef OMC_UDSADAPTER_H
#define OMC_UDSADAPTER_H

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/
#include "BUtil/GenericUDSTypes.h"
#include "Omc_Version.h"

#ifdef __cplusplus
extern "C" {
#endif
/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/
/* Check version of the module */
#if (!Omc_CHECK_VERSION(5, 1, 0))
#error "Version of Omc_UDSAdapter.h does not match the version of the module!"
#endif

/*------------------------------------------------------------------------------
                      Data Types
------------------------------------------------------------------------------*/

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

extern void Omc_UDS_RoutineControlOperatingMode_Start_ResultOk(void);

extern void Omc_UDS_RoutineControlOperatingMode_Start_ResultError(UDS_ErrorCodeType errorCode);

extern void Omc_UDS_RoutineControlExtendedOperatingMode_Start_ResultOk(void);

extern void Omc_UDS_RoutineControlExtendedOperatingMode_Start_ResultError(UDS_ErrorCodeType errorCode);

#define Omc_STOP_SEC_CODE
#include "Omc_MemMap.h" /* PRQA S 5087 */

#ifdef __cplusplus
}
#endif

#endif /* OMC_UDSADAPTER_H */
