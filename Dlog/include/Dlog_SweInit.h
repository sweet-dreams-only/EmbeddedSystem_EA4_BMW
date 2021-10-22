/**
 * \file
 *
 * \brief       Initialize Error Flags of all SWEs.
 *
 * \project     BMW Platform Software
 *
 * \copyright   BMW AG 2015 - 2017
 *
 * \version     5.3.1
 *
 */

#ifndef DLOG_SWE_INIT_H
#define DLOG_SWE_INIT_H

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "Std_Types.h"                      /* AUTOSAR Standard Types         */
#include "DlogClassic_Cfg.h"        /* DLOG_VERIFY_SWE_CRC_CHKSUM */

#include "BUtil_BitArray.h"


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
   #error "Version of Dlog_SweInit.h does not match the version of the module!"
#endif

#if ( DLOG_HANDLE_ECC_ROM == STD_ON ) || ( DLOG_VERIFY_SWE_CRC_CHKSUM == STD_ON )

/*------------------------------------------------------------------------------
                      Global Variables
-------------------------------------------------------------------------------*/

#define Dlog_START_SEC_VAR_NO_INIT_8
#include "Dlog_MemMap.h"  /* PRQA S 5087 */
   extern uint8 Dlog_SweErrorCheckDone[BUtil_CalcRequiredBytesForMultiByteBitArray( DLOG_MAX_NUMBER_OF_SWES )];
#define Dlog_STOP_SEC_VAR_NO_INIT_8
#include "Dlog_MemMap.h"  /* PRQA S 5087 */


/*------------------------------------------------------------------------------
                      Global Function Declarations
------------------------------------------------------------------------------*/

#define Dlog_START_SEC_CODE
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

extern FUNC(void, Dlog_CODE) Dlog_InitErrorFlagsOfAllSwes( void );
extern void Dlog_InitSweTable(void);

#define Dlog_STOP_SEC_CODE
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

#else
   #define Dlog_InitErrorFlagsOfAllSwes()
#endif

#endif /* DLOG_SWE_INIT_H                                                       */
