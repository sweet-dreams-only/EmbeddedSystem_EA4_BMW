/**
*  \file
*
*  \brief       Omc NVM Data
*
*  This file contains the RAM mirror and the ROM mirror of the current
*  Omc modes.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.1.0
*
*/
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

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/
/* Check version of the module */
#if (!Omc_CHECK_VERSION(5,1,0))
#error "Version of Omc_Data.c does not match the version of the module!"
#endif

/*------------------------------------------------------------------------------
                      Global Variables
------------------------------------------------------------------------------*/
#define Omc_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED
#include "Omc_MemMap.h" /* PRQA S 5087 */

/* RAM Mirror of OMC Non-volatile data */
Omc_NvDataType Omc_NvData;

#define Omc_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED
#include "Omc_MemMap.h" /* PRQA S 5087 */

/*------------------------------------------------------------------------------
                      Global Constants
------------------------------------------------------------------------------*/
/** \lhref FZM_SC_SYS_PA_187, FZM_SC_SYS_PA_340 */
#define Omc_START_SEC_CONST_SAVED_RECOVERY_ZONE
#include "Omc_MemMap.h" /* PRQA S 5087 */

/* Default data of OMC Non-volatile data */
/** \lhref FZM_SC_SYS_PA_170, FZM_SC_SYS_PA_330 */
const Omc_NvDataType Omc_DefaultNvData = { OMC_GENMODE_NORMAL, OMC_GENMODE_EXTENSION_NORMAL };

/* PRQA S 5087 2 */
#define Omc_STOP_SEC_CONST_SAVED_RECOVERY_ZONE
#include "Omc_MemMap.h" /* PRQA S 5087 */
