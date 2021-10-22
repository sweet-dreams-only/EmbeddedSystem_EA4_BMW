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


#ifndef CRYPTO_KEYMANAGEMENT_H
#define CRYPTO_KEYMANAGEMENT_H

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "BUtil/PlatformTypes.h"
#include "Crypto_Common.h"
#include <stddef.h>
#include "Crypto_Keys.h"
#include "Crypto_Version.h"

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!Crypto_CHECK_VERSION(5,2,0))
#error "Version of Crypto_KeyManagement.h does not match the version of the module!"
#endif



#ifdef __cplusplus
extern  "C" {
#endif


/*------------------------------------------------------------------------------
                      Data Types
------------------------------------------------------------------------------*/

/*
 *
 * ECDSA / RSA type definitions
 *
 */

typedef struct {
  uint32   length;
  uint8   *pubKeyX;
  uint8   *pubKeyY;
}eccPublicKeyStruct;

typedef struct {
  uint32   length;
  uint8   *pubKeyModulus;
  uint8   *pubKeyExponent;
}rsaPublicKeyStruct;


/*
 * The enum Crypto_availablePublicKeyIndex shall be used for external calls.
 * */

typedef enum {
#if  defined(CRYPTO_AUTH_KEY_LEVEL_3_SIZE)
  CRYPTO_KEY_LEVEL_3_INDEX,
#endif
#if defined(CRYPTO_AUTH_KEY_LEVEL_5_SIZE)
  CRYPTO_KEY_LEVEL_5_INDEX,
#endif
#if defined(CRYPTO_SIG_KEY_SIZE)
  CRYPTO_KEY_SIG_INDEX,
#endif
#if defined(CRYPTO_NCD_KEY_SIZE)
  CRYPTO_KEY_NCD_INDEX,
#endif
  CRYPTO_INVALID_KEY_INDEX
}Crypto_availablePublicKeyIndex;


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

#endif /* CRYPTO_KEYMANAGEMENT */
