/**
*  \file
*
*  \brief       Omc Concurrency Adapter
*
*  This file contains the Omc concurrency functionality.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.2.0
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
#include "OmcClassic_Version.h"
#include "Omc_ConcAdapter.h"
#include "Rte_Omc.h"

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/
/**
 * \brief check version of the module
 */
#if (!OmcClassic_CHECK_VERSION(5, 2, 0))
#error "Version of Omc_ConcAdapter.c does not match the version of the module!"
#endif


/*------------------------------------------------------------------------------
                      Global Variables
------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------
                      Local Data Types
 -----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Local Constants
 -----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Global Functions
------------------------------------------------------------------------------*/
#define Omc_START_SEC_CODE
#include "Omc_MemMap.h" /* PRQA S 5087 */

void Omc_CritSect_Mode_Enter(void) {
  Rte_Enter_Mode();
}

void Omc_CritSect_Mode_Exit(void) {
  Rte_Exit_Mode();
}

#define Omc_STOP_SEC_CODE
#include "Omc_MemMap.h" /* PRQA S 5087 */
