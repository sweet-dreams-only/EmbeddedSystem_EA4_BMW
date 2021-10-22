/**
*  \file
*
*  \brief       BMW SWC Dlog
*
*  This file includes all other Dlog header files needed by other modules.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.3.1
*
*/

#ifndef DLOG_H_
#define DLOG_H_

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/

#include "DlogClassic_Cfg.h"
#include "Dlog_Ecu.h"


/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/

/* Violation of MISRA rule 19.1, Reason: Including Dlog_MemMap.h is necessary throughout
   the file according to memory abstraction, see PRQA: 5087 */


/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!DlogClassic_CHECK_VERSION(5,3,1))
   #error "Version of Dlog.h does not match the version of the module!"
#endif


/*------------------------------------------------------------------------------
                      Data Types
------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------
                      Global Function Declarations
------------------------------------------------------------------------------*/

#define Dlog_START_SEC_CODE
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

#if ( DLOG_ENABLE_RTE == STD_ON )

extern FUNC(Std_ReturnType, Dlog_CODE) Dlog_GetVin(P2VAR(uint8, AUTOMATIC, Dlog_APPL_DATA) Vin);

#endif /* #if ( DLOG_ENABLE_RTE == STD_ON ) */

#define Dlog_STOP_SEC_CODE
#include "Dlog_MemMap.h"  /* PRQA S 5087 */


#endif /* DLOG_H_ */

/*--- End of file ------------------------------------------------------------*/
