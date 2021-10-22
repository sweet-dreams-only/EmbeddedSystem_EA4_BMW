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


#ifndef CRYPTO_HASH_H
#define CRYPTO_HASH_H

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "BUtil/PlatformTypes.h"
#include "Crypto_Common.h"
#include <stddef.h>
#include "Crypto_Version.h"

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!Crypto_CHECK_VERSION(5,2,0))
#error "Version of Crypto_Hash.h does not match the version of the module!"
#endif



#ifdef __cplusplus
extern  "C" {
#endif


/*------------------------------------------------------------------------------
                      Data Types
------------------------------------------------------------------------------*/

/*
 *
 * HASH type definition
 *
 * */

/* SHA 512 state can be used for SHA-384 and SHA-512. */
struct sha512_state {
  uint64 length;
  uint64 state[8];
  uint32 curlen;
  uint8  buf[128];
};

struct sha256_state {
  size_t  length;
  uint32  state[8], curlen;
  uint8   buf[64];
};


typedef union Hash_state {
  uint8   dummy[1];
  struct  sha256_state sha256;
  struct  sha512_state sha512;
  void    *data;
} hash_state;

/* This enumeration shall be used as input for the PKCS verifiy function */
/* to identify which hashing algorithm is to be used.                    */
typedef enum {
  INDEX_SHA_256 = 0,
  INDEX_SHA_384 = 1,
  INDEX_SHA_512 = 2
}hashAlgorithmIndex ;


/*------------------------------------------------------------------------------
                      Global Variables
------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------
                      Global Constants
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Global Function Declarations
------------------------------------------------------------------------------*/

/* SHA-256 */
void  Crypto_SHA256Init               (hash_state * md);
Crypto_ReturnType Crypto_SHA256Process(hash_state * md, const uint8 *in, uint32 inlen);
Crypto_ReturnType Crypto_SHA256Done   (hash_state * md, uint8 *hash);

/* SHA-384 */
void Crypto_SHA384Init                (hash_state * md);
Crypto_ReturnType Crypto_SHA384Done   (hash_state * md, uint8 *hash);
/* The SHA384 Processing is the same as the SHA512 one. */
#define Crypto_SHA384Process Crypto_SHA512Process

/* SHA-512 */
void Crypto_SHA512Init                (hash_state * md);
Crypto_ReturnType Crypto_SHA512Process(hash_state * md, const uint8 *in, uint32 inlen);
Crypto_ReturnType Crypto_SHA512Done   (hash_state * md, uint8 *hash);


#ifdef __cplusplus
}
#endif

#endif /* CRYPTO_HASH_EXTERN_H */
