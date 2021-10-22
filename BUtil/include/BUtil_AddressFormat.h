/**
*  \file
*
*  \brief       Read Address Format.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.0.3
*
*/

#ifndef BUTIL_ADDRESSFORMAT_H_
#define BUTIL_ADDRESSFORMAT_H_

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "BUtil_Types.h"                /* BUtil type definitions              */


/*------------------------------------------------------------------------------
                      Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!BUtil_CHECK_VERSION(5,0,3))
   #error "Version of BUtil_AddressFormat.h does not match the version of the module!"
#endif


/*------------------------------------------------------------------------------
                      Data Types
-------------------------------------------------------------------------------*/

typedef enum {
   BUTIL_E_AF_OK           = 0x00,
   BUTIL_E_AF_WRONG_FORMAT = 0x01,
   BUTIL_E_AF_WRONG_SIZE   = 0x02
} BUtil_AddressFormatReturnType;

typedef uint8 BUtil_FormatBuffer[];

/*------------------------------------------------------------------------------
                      Global Function Declarations
-------------------------------------------------------------------------------*/

#define BUtil_START_SEC_CODE
#include "BUtil_MemMap.h"


extern BUtil_AddressFormatReturnType BUtil_GetAddressAndLengthByFormatIdentifier
      (
        const BUtil_FormatBuffer* const reqDataPtr,
        const uint8                     addressOrLengthSize,
        const BUtil_FormatIdentifier    addressOrLengthFormatId,
        uint32* const                   pAddress,
        uint32* const                   pLength
      );


#define BUtil_STOP_SEC_CODE
#include "BUtil_MemMap.h"

#endif /* BUTIL_ADDRESSFORMAT_H_ */
