
/**
*  \file
*
*  \brief       BMW Crypto Library
*
*  This file is the extern definition header file of the generic RSA part of the
*  Crypto lib for usage in the BMW AUTOSAR Core.
*  It is to be included by the two adapaters and by any software wishing to access directly the library.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.2.0
*
*/

#ifndef CRYPTO_RSA_H
#define CRYPTO_RSA_H

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "Crypto_Common.h"
#include "Crypto_Hash.h"
#include "Crypto_KeyManagement.h"
#include "Crypto_Version.h"
/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!Crypto_CHECK_VERSION(5,2,0))
#error "Version of Crypto_RSA.h does not match the version of the module!"
#endif

/*------------------------------------------------------------------------------
                      Data Types
------------------------------------------------------------------------------*/

enum ltc_pkcs_1_paddings
{
  LTC_PKCS_1_V1_5     = 1,        /* PKCS #1 v1.5 padding (\sa ltc_pkcs_1_v1_5_blocks) */
  LTC_PKCS_1_OAEP     = 2,        /* PKCS #1 v2.0 encryption padding */
  LTC_PKCS_1_PSS      = 3,        /* PKCS #1 v2.1 signature padding */
  LTC_PKCS_1_V1_5_NA1 = 4         /* PKCS #1 v1.5 padding - No ASN.1 (\sa ltc_pkcs_1_v1_5_blocks) */
};


/*------------------------------------------------------------------------------
                      Global Function Declarations
------------------------------------------------------------------------------*/

#ifdef __cplusplus
extern  "C" {
#endif

Crypto_ReturnType Crypto_RsaVerifyHash(
  const uint8 *signature,         /* RSA signature */
  uint32 signatureLength,         /* Size of the signature in bytes */
  const uint8 *hash,              /* Hashed data */
  uint32 hashLength,              /* Size of the hash in bytes */
  uint8 padding,                  /* padding type */
  hashAlgorithmIndex hashingIndex,/* type of hashing used */
  uint32 saltLen,                 /* size of salt */
  uint8 keyIndex,                 /* Index number to the public key */
  rsaPublicKeyStruct *rawKey,     /* non formatted public key */
  sint8 *result);                 /* Result of the operation */

#ifdef __cplusplus
}
#endif

#endif /* CRYPTO_RSA_H */
