/**
*  \file
*
*  \brief       Stm Mgmt Adapter Interface
*
*  This file contains the interface definition for the Stm Management
*  Adapter.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.2.0
*
*/
#ifndef STM_MGMTADAPTER_H
#define STM_MGMTADAPTER_H

/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/
/*
   MISRA-C:2004 Rule 19.1: including Stm_MemMap.h is necessary throughout
   the file according to memory abstraction. See PRQA 5087.
*/

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/

#include "Stm_Version.h"
#include "Stm_Cfg.h"
#include "BUtil/PlatformTypes.h"    /* BMW standard types */

#ifdef __cplusplus
extern "C" {
#endif
/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* Check version of the module */
#if (!Stm_CHECK_VERSION(5,2,0))
   #error "Version of Stm_MgmtAdapter.h does not match the version of the module!"
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

#define Stm_START_SEC_CODE
#include "Stm_MemMap.h" /* PRQA S 5087 */

#if STM_CENTRAL_ERROR_LOCK_ENABLED == STD_ON

extern void Stm_Mgmt_ProvideCentralErrorLockModeUnlocked(void);
extern void Stm_Mgmt_ProvideCentralErrorLockModeLocked(void);
extern void Stm_Mgmt_ProvideCentralErrorLockModeInvalid(void);

#endif /*#if STM_CENTRAL_ERROR_LOCK_ENABLED == STD_ON*/

#define Stm_STOP_SEC_CODE
#include "Stm_MemMap.h" /* PRQA S 5087 */

#ifdef __cplusplus
}
#endif

#endif /* STM_MGMTADAPTER_H */

/*--- End of file ------------------------------------------------------------*/
