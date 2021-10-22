/**
 * \file
 *
 * \brief       Coding Crypto Adapter
 *
 * \project     BMW Platform Software
 *
 * \copyright   BMW AG 2016 - 2017
 *
 * \version     5.2.1
 *
 */

/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/

#include "Coding_CryptoAdapter.h"
#include "CodingClassic_Version.h"     /* Coding Classic Adapter Version   */
#include "Coding_Data.h"
#if (STD_ON == CODING_CRYPTO_SUPPORT)
#include "Crypto.h"
#endif /* CODING_CRYPTO_SUPPORT */
#include <string.h>                    /* Included to get access to memcpy */


/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/**
 * \brief check version of the module
 */
#if (!CodingClassic_CHECK_VERSION(5, 2, 1))
#error "Version of Coding_CryptoAdapter.c does not match the Classic adapter version!"
#endif

/**
 * \brief length of the hash for algorithm in bytes
 */
#if (STD_ON == CODING_CRYPTO_SUPPORT)
  #if defined(CRYPTO_NCD_KEY_DIGEST_SHA_256)
    #define CODING_CRYPTO_HASH_LENGTH  32u
  #elif defined(CRYPTO_NCD_KEY_DIGEST_SHA_384)
    #define CODING_CRYPTO_HASH_LENGTH  48u
  #elif defined(CRYPTO_NCD_KEY_DIGEST_SHA_512)
    #define CODING_CRYPTO_HASH_LENGTH  64u
  #else
    #error "error hash algorithm does not exist"
  #endif
#else
  #define CODING_CRYPTO_HASH_LENGTH  1u
#endif /* CODING_CRYPTO_SUPPORT */

/**
 * \brief key id to select key for ncd signature check
 */
#if (STD_ON == CODING_CRYPTO_SUPPORT)
#define CODING_CRYPTO_KEY_ID       (uint8)CRYPTO_KEY_NCD_INDEX
#endif /* CODING_CRYPTO_SUPPORT */


/*------------------------------------------------------------------------------
                      Local Functions Prototypes
-------------------------------------------------------------------------------*/

#define Coding_START_SEC_CODE
#include "Coding_MemMap.h" /* PRQA S 5087 */

#if (CODING_CRYPTO_SUPPORT == STD_ON)
static void Coding_Crypto_HashInit(hash_state* hashCtx);

static void Coding_Crypto_HashUpdate(hash_state* hashCtx, const uint8* data, size_t size);

static void Coding_Crypto_HashFinish(hash_state* hashCtx, uint8* hash);
#endif /* CODING_CRYPTO_SUPPORT */

static void Coding_Crypto_CalculateHash(const uint8* data, size_t dataLength, uint8* hash);

static Coding_Crypto_VerifyState Coding_Crypto_SignatureVerify(
    const uint8* signature, size_t signatureLength, const uint8* hash, size_t hashLength);


/*------------------------------------------------------------------------------
                      Local Functions
-------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/**
 * Service that manage the hash init service
 */
/*----------------------------------------------------------------------------*/
#if (CODING_CRYPTO_SUPPORT == STD_ON)
static void Coding_Crypto_HashInit(hash_state* hashCtx) {
  #if defined(CRYPTO_NCD_KEY_DIGEST_SHA_256)
    Crypto_SHA256Init(hashCtx);
  #elif defined(CRYPTO_NCD_KEY_DIGEST_SHA_384)
    Crypto_SHA384Init(hashCtx);
  #elif defined(CRYPTO_NCD_KEY_DIGEST_SHA_512)
    Crypto_SHA512Init(hashCtx);
  #endif
}
#endif /* CODING_CRYPTO_SUPPORT */

/*----------------------------------------------------------------------------*/
/**
 * Service that manage the hash update service
 */
/*----------------------------------------------------------------------------*/
#if (CODING_CRYPTO_SUPPORT == STD_ON)
static void Coding_Crypto_HashUpdate(hash_state* hashCtx, const uint8* data, size_t size) {
  #if defined(CRYPTO_NCD_KEY_DIGEST_SHA_256)
    (void)Crypto_SHA256Process(hashCtx, data, (uint32) size);
  #elif defined(CRYPTO_NCD_KEY_DIGEST_SHA_384)
    (void)Crypto_SHA384Process(hashCtx, data, (uint32) size);
  #elif defined(CRYPTO_NCD_KEY_DIGEST_SHA_512)
    (void)Crypto_SHA512Process(hashCtx, data, (uint32) size);
  #endif
}
#endif /* CODING_CRYPTO_SUPPORT */

/*----------------------------------------------------------------------------*/
/**
 * Service that manage the hash finish service
 */
/*----------------------------------------------------------------------------*/
#if (CODING_CRYPTO_SUPPORT == STD_ON)
static void Coding_Crypto_HashFinish(hash_state* hashCtx, uint8* hash) {
  #if defined(CRYPTO_NCD_KEY_DIGEST_SHA_256)
    (void)Crypto_SHA256Done(hashCtx, hash);
  #elif defined(CRYPTO_NCD_KEY_DIGEST_SHA_384)
    (void)Crypto_SHA384Done(hashCtx, hash);
  #elif defined(CRYPTO_NCD_KEY_DIGEST_SHA_512)
    (void)Crypto_SHA512Done(hashCtx, hash);
  #endif
}
#endif /* CODING_CRYPTO_SUPPORT */

/*----------------------------------------------------------------------------*/
/**
 * Service that manage the hash calculation
 */
/*----------------------------------------------------------------------------*/
static void Coding_Crypto_CalculateHash(
    const uint8* data,
    size_t dataLength,
    uint8* hash) {
#if (STD_ON == CODING_CRYPTO_SUPPORT)
  hash_state hashCtx; /* PRQA S 0759 */
  Coding_Crypto_HashInit(&hashCtx);
  Coding_Crypto_HashUpdate
      (
          &hashCtx,
          data,  /* pointer to the data */
          dataLength
      );
  Coding_Crypto_HashFinish(&hashCtx, hash);
#else
  /* Nothing to do, because Crypto is disabled */
  (void)data;
  (void)dataLength;
  (void)hash;
#endif /* CODING_CRYPTO_SUPPORT */
}

/*----------------------------------------------------------------------------*/
/**
 * Service that manage the signature verify service
 */
/*----------------------------------------------------------------------------*/
static Coding_Crypto_VerifyState Coding_Crypto_SignatureVerify(
    const uint8* signature, size_t signatureLength,
    const uint8* hash, size_t hashLength) {
#if (CODING_CRYPTO_SUPPORT == STD_ON)
  Coding_Crypto_VerifyState retValue;
  Crypto_ReturnType retVerify;
  sint8 result;

#if (defined (CRYPTO_NCD_KEY_ECC_PARAM_SECP256R1) || \
     defined (CRYPTO_NCD_KEY_ECC_PARAM_SECP384R1) || \
     defined (CRYPTO_NCD_KEY_ECC_PARAM_SECP521R1))
  retVerify = Crypto_EccVerifyHash
     (
         signature,
         (signatureLength/2u),  /* TODO: e.g. 96 = 2*48 Bytes */
         hash,
         hashLength,
         CODING_CRYPTO_KEY_ID,
         (eccPublicKeyStruct*)NULL,
         &result
     );
#else
  retVerify = Crypto_RsaVerifyHash
     (
         signature,
         (uint32)signatureLength,
         hash,
         (uint32)hashLength,
         (uint8)LTC_PKCS_1_PSS,
  #if defined(CRYPTO_NCD_KEY_DIGEST_SHA_256)
         INDEX_SHA_256,
  #elif defined(CRYPTO_NCD_KEY_DIGEST_SHA_384)
         INDEX_SHA_384,
  #elif defined(CRYPTO_NCD_KEY_DIGEST_SHA_512)
         INDEX_SHA_512,
  #endif
         CODING_CRYPTO_HASH_LENGTH,
         CODING_CRYPTO_KEY_ID,
         (rsaPublicKeyStruct*)NULL,
         &result
     );
#endif /* CRYPTO_NCD_KEY_ECC_PARAM_SECPxxxR1 */

  if ( (result == (sint8)CRYPTO_E_OK) &&
       (retVerify == CRYPTO_E_OK) ) {
    retValue = CODING_CRYPTO_VERIFIED;
  } else {
    retValue = CODING_CRYPTO_NOT_VERIFIED;
  }
  return (retValue);
#else
  /* Nothing to do, because Crypto is disabled */
  (void)signature;
  (void)signatureLength;
  (void)hash;
  (void)hashLength;
  return (CODING_CRYPTO_VERIFIED);
#endif /* CODING_CRYPTO_SUPPORT */
}


/*------------------------------------------------------------------------------
                      Global Functions
------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/**
 * Service that manage the signature check service
 */
/*----------------------------------------------------------------------------*/
Coding_Crypto_VerifyState Coding_Crypto_SignatureCheck(
    uint8 codingAreaIdx, const uint8* cps) {
  Coding_Crypto_VerifyState verifyState = CODING_CRYPTO_NOT_VERIFIED;
  uint8 hash[CODING_CRYPTO_HASH_LENGTH];
  /* temporary data buffer includes hash and cps */
  uint8 tmpData[CODING_CRYPTO_HASH_LENGTH + CODING_CPS_SIZE];

  Coding_Crypto_CalculateHash /* calculate hash (user and logistic data (CAF-ID)) */
      (
          &Coding_CodingData[Coding_AreaOffsetTable[codingAreaIdx]],  /* pointer to the data */
          /* Coding_AreaSizeTable[] always includes signature block size */
          (size_t)((uint32)Coding_AreaSizeTable[codingAreaIdx] -
                   CODING_SIGNATURE_BLOCK_SIZE),  /* PRQA S 4391 *//* length of the data in bytes */
          hash  /* pointer to the hash buffer */
      );

  (void)memcpy  /* copy already calculated hash to temporary data buffer */
      (
          tmpData,
          hash,
          sizeof(hash)
      );

  (void)memcpy  /* append cps to the temporary data buffer */
      (
          &tmpData[CODING_CRYPTO_HASH_LENGTH],
          cps,
          CODING_CPS_SIZE
      );

  Coding_Crypto_CalculateHash /* calculate hash (hash and CPS)   */
      (
          tmpData,         /* pointer to the temporary data buffer     */
          sizeof(tmpData), /* length of the temp data buffer in bytes  */
          hash             /* pointer to the hash buffer               */
      );

  verifyState = Coding_Crypto_SignatureVerify
      (
          &Coding_CodingData[                           /* pointer to the signature    */
              (Coding_AreaOffsetTable[codingAreaIdx] +
               Coding_AreaSizeTable[codingAreaIdx]) -
              CODING_SIGNATURE_BLOCK_SIZE
          ],
          (size_t)CODING_SIGNATURE_BLOCK_SIZE,
          hash,
          sizeof(hash)
      );

  return(verifyState);
}

#define Coding_STOP_SEC_CODE
#include "Coding_MemMap.h" /* PRQA S 5087 */
