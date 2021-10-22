/**
*  \file
*
*  \brief       BMW Crypto Library
*
*  This file is the header file containing the defines for the key management of the Crypto lib
*  for usage in the BMW AUTOSAR Core.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.2.0
*
*/

#ifndef CRYPTO_KEYMANAGEMENT_INTERN_H
#define CRYPTO_KEYMANAGEMENT_INTERN_H

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/
#include "Crypto_RSA_Intern.h"
#include "Crypto_ECDSA_Intern.h"
#include "Crypto_Common_Intern.h"
#include "Crypto_Keys.h"
#include "Crypto_Version.h"


#ifdef __cplusplus
extern  "C" {
#endif

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!Crypto_CHECK_VERSION(5,2,0))
#error "Version of Crypto_KeyManagementIntern.h does not match the version of the module!"
#endif
/*------------------------------------------------------------------------------
                      Data Types
------------------------------------------------------------------------------*/

/* Defining which type of key we have */
typedef enum {
  PK_RSA   = 0 ,
  PK_ECDSA = 1
}keyType_t;

typedef  struct {
  const uint32* keyX;     /* Public key X point coordinate */
  const uint32* keyY;     /* Public key Y point coordinate */
  uint32  keySize;  /* Public key size */
}eccPublicKeyType;

typedef struct {
  const uint32* pubExp;  /* Public exponent of the RSA key */
  const uint32* modulus; /* modulus of the RSA Key */
  uint32 keySize;        /* modulus size */
}rsaPublicKeyType;

typedef struct{
  const void* key;   /* Pointer to the key */
  keyType_t keyType; /* Which algorithm is this key for */
}publicKeyType;


/*------------------------------------------------------------------------------
                      Global Functions
------------------------------------------------------------------------------*/

void Crypto_makeECDSAKeyStruct(eccPublicKeyStruct *inputData, ecc_key *targetKey);
Crypto_ReturnType Crypto_getKeybyIndex(void* publicKey, uint8 keyIndex, keyType_t keyType);


#ifdef __cplusplus
}
#endif

#endif /*CRYPTO_KEYMANAGEMENT_INTERN_H*/
