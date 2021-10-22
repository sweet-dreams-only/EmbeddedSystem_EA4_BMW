/**
*  \file
*
*  \brief       BMW Crypto Library
*
*  This file is the extern definition header file of the generic part of the
*  Crypto lib for usage in the BMW AUTOSAR Core.
*  It is to be included by the two adapaters and by any software wishing to acess directly the library.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.2.0
*
*/


#ifndef CRYPTO_COMMON_H
#define CRYPTO_COMMON_H

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "BUtil/PlatformTypes.h"
#include <stddef.h>
#include "Crypto_Version.h"

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!Crypto_CHECK_VERSION(5,2,0))
#error "Version of Crypto_Common.h does not match the version of the module!"
#endif


#ifdef __cplusplus
extern  "C" {
#endif


/*------------------------------------------------------------------------------
                      Data Types
------------------------------------------------------------------------------*/

/* Communal return type used in all functions. */
typedef enum  {
  CRYPTO_E_OK                 = 0x0u,
  CRYPTO_E_NOK                = 0x1u,
  CRYPTO_E_BUSY               = 0x2u,
  CRYPTO_E_SMALL_BUFFER       = 0x3u,
  CRYPTO_E_ENTROPY_EXHAUSTION = 0x4u,
  CRYPTO_E_QUEUE_FULL         = 0x5u,
  CRYPTO_E_KEY_READ_FAIL      = 0x6u,
  CRYPTO_E_KEY_WRITE_FAIL     = 0x7u,
  CRYPTO_E_KEY_NOT_AVAILABLE  = 0x8u,
  CRYPTO_E_KEY_NOT_VALID      = 0x9u,
  CRYPTO_E_KEY_SIZE_MISMATCH  = 0xau,
  CRYPTO_E_COUNTER_OVERFLOW   = 0xbu,
  CRYPTO_E_JOB_CANCELED       = 0xcu
} Crypto_ReturnType;

/* Public key - Private Key enum */
enum {
  PK_PUBLIC=0,
  PK_PRIVATE=1
};

/*------------------------------------------------------------------------------
                      Global Variables
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Global Constants
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Global Function Declarations
------------------------------------------------------------------------------*/





#ifdef __cplusplus
}
#endif

#endif /* CRYPTO_EXTERN_H */
