/**
*  \file
*
*  \brief       BMW Crypto Library
*
*  This file contains the certificate management functions of the BMW Crypto Library.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.2.0
*
*/

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "Crypto_CertificateManagement.h"
#include <string.h>

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!CryptoClassic_CHECK_VERSION(5,2,0))
#error "Version of Crypto_CertificateManagement.h does not match the version of the module!"
#endif

/*------------------------------------------------------------------------------
                      Macros
-------------------------------------------------------------------------------*/

#define SIZE_OF_SHA256_IN_BYTES 32
#define SIZE_OF_SHA384_IN_BYTES 48
#define SIZE_OF_SHA512_IN_BYTES 64

#define SIZE_OF_SIGNATURE_P256_IN_BYTES 32
#define SIZE_OF_SIGNATURE_P384_IN_BYTES 48
#define SIZE_OF_SIGNATURE_P521_IN_BYTES 66

#define ECDSA_WITH_SHA256_OID {0x2A, 0x86, 0x48, 0xCE, 0x3D, 0x04, 0x03, 0x02}       /* ecdsa_with_SHA256_OID (8 bytes long). */
#define ECDSA_WITH_SHA384_OID {0x2A, 0x86, 0x48, 0xCE, 0x3D, 0x04, 0x03, 0x03}       /* ecdsa_with_SHA384_OID (8 bytes long). */
#define ECDSA_WITH_SHA512_OID {0x2A, 0x86, 0x48, 0xCE, 0x3D, 0x04, 0x03, 0x04}       /* ecdsa_with_SHA512_OID (8 bytes long). */
#define SHA256_WITH_RSA       {0x2A, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01, 0x0b}, /* sha256WithRSAEncryption. */
#define SHA384_WITH_RSA       {0x2A, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01, 0x0c}, /* sha384WithRSAEncryption. */
#define SHA512_WITH_RSA       {0x2A, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01, 0x0d}, /* sha512WithRSAEncryption. */

#define  Crypto_START_SEC_CODE
#include "Crypto_MemMap.h"

/*------------------------------------------------------------------------------
                      Local Variables
-------------------------------------------------------------------------------*/

/* ToDo: update list of supported algorithms with RSA. */

/* we need to have at least one hash and one signature verification function activated. */
/* hash functions */
/* signature functions */


/* List of supported signature algorithms */
static const struct {
  /* OID */
  uint8 OID[9];
  /* Hash init function  */
  void (*hashInit) (hash_state *);
  /* Hash process function */
  Crypto_ReturnType (*hashProcess) (hash_state *, const uint8*, uint32);
  /* Hash done function */
  Crypto_ReturnType (*hashDone)    (hash_state * md, uint8 *hash);
  /* Signature verification */
  Crypto_ReturnType (*signatureVerification)    (const uint8* , size_t , const uint8* , size_t, uint8 , eccPublicKeyStruct* , sint8* );
  /* Hash size (in bytes) */
  uint8 hashSize;
} listSignatureAlgorithm[] = {
    {ECDSA_WITH_SHA256_OID, &Crypto_SHA256Init, &Crypto_SHA256Process, &Crypto_SHA256Done, &Crypto_EccVerifyHash, SIZE_OF_SHA256_IN_BYTES},
      {ECDSA_WITH_SHA384_OID, &Crypto_SHA384Init, &Crypto_SHA384Process, &Crypto_SHA384Done, &Crypto_EccVerifyHash, SIZE_OF_SHA384_IN_BYTES},
      {ECDSA_WITH_SHA512_OID, &Crypto_SHA512Init, &Crypto_SHA512Process, &Crypto_SHA512Done, &Crypto_EccVerifyHash, SIZE_OF_SHA512_IN_BYTES},
  };


/*------------------------------------------------------------------------------
                      Global Functions
-------------------------------------------------------------------------------*/


/**
 *
 * This functions goes through a DER-Encoded certificate and verifies the signature with the key given as parameter.
 *
 * \param[in]  cert     Pointer to the 1st element of the x509 certificate.
 * \param[in]  rawKey   Pointer to the public key used for verification.
 * \param[out] result   Result of the verification.
 *
 * \retval CRYPTO_E_OK  Parsing, Hashing and verification was successfully executed.
 * \retval CRYPTO_E_NOK An error occurred during certificate verification.
 *
 * \pre cert is a valid pointer (not checked).
 * \pre rawKey is a valid pointer (not checked).
 * \pre result is a valid pointer (not checked).
 *
 * \post result contains the verification result
 *  or CRYPTO_E_NOK is returned.
 *
 **/


Crypto_ReturnType Crypto_CertVerifiy( const uint8 *cert,
                                      eccPublicKeyStruct *rawKey,
                                      sint8* result)
{
  /* Return value */
  Crypto_ReturnType         retVal;
  /* Parsing result  */
  Crypto_certifParseResult  parseResult;
  /* Hash context */
  hash_state                myHashState;
  /* Hash result */
  uint8                     hashResult[SIZE_OF_SHA512_IN_BYTES];
  /* The formatted signature contains R and S and therefore needs twice the size */
  uint8                     formattedSignature[2*SIZE_OF_SIGNATURE_P521_IN_BYTES];
  /* Signature length in bytes */
  uint16                    signatureLength;
  /* Algorithm index */
  uint8                     algoIndex;

  *result = CRYPTO_E_NOK;

  /* parse the certificate to retrieve the information needed for verification  */
  retVal = Crypto_CertParse(cert, &parseResult);
  if (retVal != CRYPTO_E_OK)
  {
    return retVal;
  }

  /* identifying the correct algorithm */
  for(algoIndex = 0 ; algoIndex < (sizeof(listSignatureAlgorithm)/ sizeof(listSignatureAlgorithm[0])) ; algoIndex++)
  {
    if(memcmp(listSignatureAlgorithm[algoIndex].OID, parseResult.signatureAlgorithmPointer, parseResult.signatureAlgorithmLength) == 0)
    {
      /* Performing hashing of the certificate. */
      listSignatureAlgorithm[algoIndex].hashInit(&myHashState);
      if(listSignatureAlgorithm[algoIndex].hashProcess(&myHashState, parseResult.TBSCertPointer, parseResult.TBSCertLength) != CRYPTO_E_OK)
      {
        return  CRYPTO_E_NOK;
      }
      if(listSignatureAlgorithm[algoIndex].hashDone   (&myHashState, hashResult) != CRYPTO_E_OK)
      {
        return  CRYPTO_E_NOK;
      }

      /* Signature formatting. */
      if(Crypto_EcdsaSignatureParse(parseResult.signaturePointer, formattedSignature, &signatureLength ) != CRYPTO_E_OK)
      {
        return  CRYPTO_E_NOK;
      }
      /* Performing certificate verification. */
      retVal = listSignatureAlgorithm[algoIndex].signatureVerification( formattedSignature,                        /* signature */
                                                                        signatureLength,                           /* signature length in bytes */
                                                                        hashResult,                                /* hash */
                                                                        listSignatureAlgorithm[algoIndex].hashSize,/* hashLength */
                                                                        0,                                         /* keyIndex - not relevant in this case */
                                                                        rawKey,                                    /* rawKey */
                                                                        result);                                   /* result of the verification. */
      return retVal;
    }
  }

  /* if we reach this line, it means the signature algorithm is not supported. */
  return CRYPTO_E_NOK;

}


#define  Crypto_STOP_SEC_CODE
#include "Crypto_MemMap.h"


