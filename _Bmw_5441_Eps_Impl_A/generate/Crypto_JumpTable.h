/**
*  \file
*
*  \brief       BMW Crypto Library
*
*  This file contains the jumptable type used for direct access to the crypto routines. (e.g. : from the bootloader)
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.2.0
*
*/

/*------------------------------------------------------------------------------
*
*  THIS FILE WAS GENERATED. DO NOT MODIFY!
*
*  GENERATOR       : BMW PAGe 1.1.0
*
*  GENERATION TIME : 2018-07-30 19:57:39.411029
*
------------------------------------------------------------------------------*/


#ifndef PROJECT_CRYPTO_JUMPTABLE_H
#define PROJECT_CRYPTO_JUMPTABLE_H

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "Crypto.h"
#include "Crypto_CertificateManagement.h"
#include "CryptoClassic_Version.h"

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!CryptoClassic_CHECK_VERSION(5,2,0))
#error "Version of Crypto_JumpTable.h does not match the version of the module!"
#endif



/*------------------------------------------------------------------------------
                      Data Types
------------------------------------------------------------------------------*/

typedef struct {
  /* SHA256 hash functions */
  void              (*Crypto_SHA256Init)       (hash_state * md);
  Crypto_ReturnType (*Crypto_SHA256Process)    (hash_state * md, const uint8 *in, uint32 inlen);
  Crypto_ReturnType (*Crypto_SHA256Done)       (hash_state * md, uint8 *hash);
/* SHA384 hash functions */
/* Crypto_SHA384Process does not exist, for SHA-384, the function Crypto_SHA512Process shall be used instead. */
void              (*Crypto_SHA384Init)       (hash_state * md);
Crypto_ReturnType (*Crypto_SHA384Done)       (hash_state * md, uint8 *hash);
/* SHA512 hash functions */
void              (*Crypto_SHA512Init)       (hash_state * md);
Crypto_ReturnType (*Crypto_SHA512Process)    (hash_state * md, const uint8 *in, uint32 inlen);
Crypto_ReturnType (*Crypto_SHA512Done)       (hash_state * md, uint8 *hash);
/* ECDSA signature verification  */
Crypto_ReturnType (*Crypto_EccVerifyHash)    (const uint8* signature, size_t signatureLength, const uint8* hash, size_t hashLength, uint8 keyIndex, eccPublicKeyStruct *rawKey, sint8 *result);
Crypto_ReturnType (*Crypto_RsaVerifyHash)     (const uint8 *signature, uint32 signatureLength, const uint8 *hash, uint32 hashLength, uint8 padding, hashAlgorithmIndex hashingIndex, uint32 saltLen, uint8 keyIndex, rsaPublicKeyStruct *rawKey, sint8 *result);
/* Certificate signature verification  */
Crypto_ReturnType (*Crypto_CertVerifiy)      (const uint8 *cert, eccPublicKeyStruct *rawKey, sint8* result);
}Crypto_JumpTableStruct;

/*------------------------------------------------------------------------------
                      Global Variables
------------------------------------------------------------------------------*/

#define  Crypto_START_SEC_CONST_JUMPTABLE
#include "Crypto_MemMap.h"

extern  volatile const Crypto_JumpTableStruct CryptoJumptable;

#define  Crypto_STOP_SEC_CONST_JUMPTABLE
#include "Crypto_MemMap.h"



#endif /* PROJECT_CRYPTO_JUMPTABLE_H */
