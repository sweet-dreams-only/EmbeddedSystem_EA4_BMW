/*----------------------------------------------------------------------------*/
/**
 * \file
 *
*  \brief       BMW SWC Dlog
*
*  This file contains the postbuild configuration of Dlog.
*
 * \project     BMW AUTOSAR Core
 *
 * \par         To be changed by user:
 *              [no]
 *
 * \copyright   BMW AG 2015 - 2016
 *
 *  \version     5.3.1
 *
 */
/*----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "Dlog_PBCfg.h"
#include "Dlog_Data.h"
#include "Dlog_HweTable.h"


/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/

/* Violation of MISRA rule 19.1, Reason: Including Dlog_MemMap.h is necessary throughout
   the file according to memory abstraction, see PRQA: 5087 */


/*------------------------------------------------------------------------------
                        Local Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!DlogClassic_CHECK_VERSION(5,3,1))
   #error "Version of Dlog_PBCfg.c does not match the version of the module!"
#endif


/*------------------------------------------------------------------------------
                      Global Constants
------------------------------------------------------------------------------*/

#define Dlog_START_SEC_CONST_UNSPECIFIED
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

const Dlog_PBConfigType Dlog_Config = {
48,
0
};


#define Dlog_STOP_SEC_CONST_UNSPECIFIED
#include "Dlog_MemMap.h"  /* PRQA S 5087 */


/*------------------------------------------------------------------------------
                      Global Variables
-------------------------------------------------------------------------------*/

#define Dlog_START_SEC_VAR_INIT_UNSPECIFIED
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

const Dlog_PBConfigType* Dlog_PBConfigSetPtr = &Dlog_Config;

#define Dlog_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

/*------------------------------------------------------------------------------
                      Local Constants
------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------
                      Local Functions Prototypes
-------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------
                      Local Functions
-------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------
                      Global Functions
-------------------------------------------------------------------------------*/

#define Dlog_START_SEC_CODE
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

/**
 * \brief Function to select Post Build configuration
 */
extern void Dlog_SetConfiguration(const Dlog_PBConfigType* selectedConfig)
{
  Dlog_PBConfigSetPtr = selectedConfig;
  Dlog_InitHweTable();
}


#define Dlog_STOP_SEC_CODE
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

