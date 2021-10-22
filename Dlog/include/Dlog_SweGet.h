/**
 * \file
 *
 * \brief       Get SWE related data.
 *
 * \project     BMW Platform Software
 *
 * \copyright   BMW AG 2015 - 2017
 *
 * \version     5.3.1
 *
 */

#ifndef DLOG_SWE_GET_H
#define DLOG_SWE_GET_H


/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/
#include <Std_Types.h>            /* AUTOSAR Standard Types                   */
#include "DlogClassic_Cfg.h"
#include "Dlog_Swe.h"             /* contains Dlog_SweProgDepStateType        */
/* -------------------------------------------------------------------------- */
#if (DLOG_ENABLE_RTE == STD_ON)
#include "Rte_Dlog.h"
#else
#include "Dlog_Rte2C.h"
#endif
/* -------------------------------------------------------------------------- */
#include <stddef.h>


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
   #error "Version of Dlog_SweGet.h does not match the version of the module!"
#endif


/*------------------------------------------------------------------------------
                      Data Types
------------------------------------------------------------------------------*/

typedef enum
{
   DLOG_SWE_VALID = 0x5A5Au,
   DLOG_SWE_NOT_VALID = 0x0000u
} Dlog_SweValidFlagType;


/*------------------------------------------------------------------------------
                      Global Variables
-------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Global Function Declarations
------------------------------------------------------------------------------*/

#if (DLOG_ENABLE_SWE_GET == STD_ON)

#define Dlog_START_SEC_CODE
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

extern Dlog_SweValidStateType Dlog_CheckValidStateOfSwe(uint8 sweId);

extern FUNC(Dlog_SweProgDepStateType, Dlog_CODE) Dlog_GetProgDepStateOfSwe
       (
          VAR(uint8, AUTOMATIC) sweId
       );
extern Dlog_SweProgDepStateType Dlog_GetCheckedProgDepStateOfSwe
       (
          uint8 sweId,
          uint32* counter,
          uint8* fingerprint,
          uint8* progId
       );
extern Dlog_SweProgDepStateType Dlog_GetProgDepStateOfApplSwes( uint8* fingerprint, uint8* progId );

#if (DLOG_HANDLE_ECC_SWE_ERRORS == STD_ON ) || ( DLOG_ENABLE_SWE_PERFORM_ERROR_CHECK == STD_ON )
   #if ( DLOG_VERIFY_SWE_CRC_CHKSUM == STD_ON ) || ( DLOG_HANDLE_ECC_ROM == STD_ON )
   extern void Dlog_GetAddressOfFlashSegmentContainingValidFlag
          (
              uint8 sweId,
              size_t* segmentStartAddress,
              size_t* segmentEndAddress
          );
   #endif
#endif

#define Dlog_STOP_SEC_CODE
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

#endif /* #if (DLOG_ENABLE_SWE_GET == STD_ON) */

#endif /* DLOG_SWE_GET_H                                                       */
