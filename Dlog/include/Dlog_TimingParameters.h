/**
 * \file
 *
 * \brief       Read timing parameters.
 *
 * \project     BMW Platform Software
 *
 * \copyright   BMW AG 2015 - 2017
 *
 * \version     5.3.1
 *
 */

#ifndef DLOG_TIMING_PARAMETERS_H
#define DLOG_TIMING_PARAMETERS_H

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include <Std_Types.h>                      /* AUTOSAR Standard Types         */
#include "DlogClassic_Cfg.h"
#if ( DLOG_ENABLE_RTE == STD_ON )
#include <Rte_Dlog_Type.h>
#else
#include "Dcm_Types.h"
#endif


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
   #error "Version of Dlog_TimingParameters.h does not match the version of the module!"
#endif

/*------------------------------------------------------------------------------
                      Global Function Declarations
------------------------------------------------------------------------------*/

#define Dlog_START_SEC_CODE
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

extern Std_ReturnType Dlog_ReadDataByIdentifierFlashTimingParameter(uint8* const Data);

#define Dlog_STOP_SEC_CODE
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

#endif  /* DLOG_TIMING_PARAMETERS_H                                                */
