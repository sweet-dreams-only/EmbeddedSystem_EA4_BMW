/**
 * \file
 *
 * \brief       The SWE status contains the error flags for each SWE.
 *
 * \project     BMW Platform Software
 *
 * \copyright   BMW AG 2015 - 2017
 *
 * \version     5.3.1
 *
 */

#ifndef DLOGSWESTATUS_H_
#define DLOGSWESTATUS_H_


/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include <Std_Types.h>            /* AUTOSAR Standard Types                   */
#include "DlogClassic_Cfg.h"
#include "Dlog_Data.h"
#include "BUtil_BitArray.h"


/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/

/* Violation of MISRA rule 19.1, Reason: Including Dlog_MemMap.h is necessary throughout
   the file according to memory abstraction, see PRQA: 5087 */

/* Violation of MISRA rule 19.7, Reason: C90 does not support inline
 * functions, see PRQA 3453
 */


/*------------------------------------------------------------------------------
                      Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!DlogClassic_CHECK_VERSION(5,3,1))
   #error "Version of Dlog_SweStatus.h does not match the version of the module!"
#endif

#if ( DLOG_HANDLE_ECC_ROM == STD_ON )
   #define Dlog_GetEccErrorFlagOfSwe( sweId )                                   \
      ( BUtil_GetBitInMultiByteBitArray( Dlog_SweStatus.EccError, sweId ) != 0u ) /* PRQA S 3453 */
   #define Dlog_SetEccErrorFlagOfSwe( sweId )                                   \
      BUtil_SetBitInMultiByteBitArray( Dlog_SweStatus.EccError, sweId ) /* PRQA S 3453 */
   #define Dlog_ClearEccErrorFlagOfSwe( sweId )                                 \
      BUtil_ClearBitInMultiByteBitArray( Dlog_SweStatus.EccError, sweId ) /* PRQA S 3453 */
#endif
#if ( DLOG_VERIFY_SWE_CRC_CHKSUM == STD_ON )
   #define Dlog_GetCrcErrorFlagOfSwe( sweId )                                   \
      ( BUtil_GetBitInMultiByteBitArray( Dlog_SweStatus.CrcError, sweId ) != 0u ) /* PRQA S 3453 */
   #define Dlog_SetCrcErrorFlagOfSwe( sweId )                                   \
      BUtil_SetBitInMultiByteBitArray( Dlog_SweStatus.CrcError, sweId ) /* PRQA S 3453 */
   #define Dlog_ClearCrcErrorFlagOfSwe( sweId )                                 \
      BUtil_ClearBitInMultiByteBitArray( Dlog_SweStatus.CrcError, sweId ) /* PRQA S 3453 */
#endif


/*------------------------------------------------------------------------------
                      Data Types
-------------------------------------------------------------------------------*/

typedef struct {
   /** 0 = ok, 1 = ECC error occured *
    * Bit 0: Bootloader SWE          *
    * Bit 1: Application SWE 1       *
    * ...                            *
    * Bit n: Application SWE n       */
   uint8 EccError[BUtil_CalcRequiredBytesForMultiByteBitArray(DLOG_MAX_NUMBER_OF_SWES)];

   /** 0 = ok, 1 = CRC error occured *
    * Bit 0: Bootloader SWE          *
    * Bit 1: Application SWE 1       *
    * ...                            *
    * Bit n: Application SWE n       */
   uint8 CrcError[BUtil_CalcRequiredBytesForMultiByteBitArray(DLOG_MAX_NUMBER_OF_SWES)];
} Dlog_SweStatusType;


/*------------------------------------------------------------------------------
                      Global Variables
-------------------------------------------------------------------------------*/

#define Dlog_START_SEC_VAR_SHARED_SWESTATUS
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

extern Dlog_SweStatusType Dlog_SweStatus;

extern Dlog_SweInfoType Dlog_SweInfos[DLOG_MAX_NUMBER_OF_SWES];

#define Dlog_STOP_SEC_VAR_SHARED_SWESTATUS
#include "Dlog_MemMap.h"  /* PRQA S 5087 */


/*------------------------------------------------------------------------------
                      Global Function Declarations
-------------------------------------------------------------------------------*/

#define Dlog_START_SEC_CODE
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

extern void Dlog_CopySweDescription(uint8 sweId);
extern void Dlog_SetSweValidState(uint8 sweId, Dlog_SweValidStateType validState);
extern Dlog_SweValidStateType Dlog_GetSweValidState(uint8 sweId);

extern void Dlog_SetSweProgDepState(Dlog_SweProgDepStateType progDepState);
extern Dlog_SweProgDepStateType Dlog_GetSweProgDepState(void);

#define Dlog_STOP_SEC_CODE
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

#endif /* DLOGSWESTATUS_H_ */
