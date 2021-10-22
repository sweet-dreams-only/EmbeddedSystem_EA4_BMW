/**
*  \file
*
*  \brief       BMW SWC StdDiag
*
*  This file is the post build configuration source file of the module StdDiag
*  for usage in the BMW AUTOSAR Core.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2017
*
*  \version     5.4.0
*
*  \remarks     The StdDiag module is responsible for BMW specific session
*               handling and handles a number of BMW specific diagnostic requests.
*
*/

/*------------------------------------------------------------------------------
*
*  THIS FILE WAS GENERATED. DO NOT MODIFY!
*
*  GENERATOR       : BMW PAGe 1.1.0
*
*  GENERATION TIME : 2018-07-30 19:57:43.154403
*
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/
/*
   MISRA-C:2004 Rule 19.1: including StdDiag_MemMap.h is necessary throughout
   the file according to memory abstraction. See PRQA 5087.
*/

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/

#include "StdDiagClassic_Version.h"
#include "StdDiagClassic_PBCfg.h"

/*------------------------------------------------------------------------------
                      Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!StdDiagClassic_CHECK_VERSION(5,4,0))
   #error "Version of StdDiagClassic_PBCfg.c does not match the version of the module!"
#endif


/*------------------------------------------------------------------------------
                      Constants
------------------------------------------------------------------------------*/
/* PRQA S 5087 2 */
#define StdDiag_START_SEC_CONST_UNSPECIFIED
#include "StdDiag_MemMap.h"

/**
 * \brief SGBD Index
 *
 * These constants specify the possible SGBD Indexes to be read
 * via UDS Service $22 $F1 $50
 */
const StdDiag_PBConfigType StdDiag_Config = {{0x0Fu, 0x28u, 0xD0u}};


/* PRQA S 5087 2 */
#define StdDiag_STOP_SEC_CONST_UNSPECIFIED
#include "StdDiag_MemMap.h"

/*------------------------------------------------------------------------------
                      Global Variables
-------------------------------------------------------------------------------*/

/* PRQA S 5087 2 */
#define StdDiag_START_SEC_VAR_INIT_UNSPECIFIED
#include "StdDiag_MemMap.h"

const StdDiag_PBConfigType * StdDiag_PBConfigSetPtr = &StdDiag_Config;

/* PRQA S 5087 2 */
#define StdDiag_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "StdDiag_MemMap.h"

/*------------------------------------------------------------------------------
                      Global Functions
-------------------------------------------------------------------------------*/

/* PRQA S 5087 2 */
#define StdDiag_START_SEC_CODE
#include "StdDiag_MemMap.h"

/**
 * \brief Function to select Post Build configuration
 */
void StdDiag_SetConfiguration
(
    const StdDiag_PBConfigType * selectedConfig
)
{
   StdDiag_PBConfigSetPtr = selectedConfig;
}

/* PRQA S 5087 2 */
#define StdDiag_STOP_SEC_CODE
#include "StdDiag_MemMap.h"

