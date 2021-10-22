/**
*  \file
*
*  \brief       BMW Crypto Library
*
*  This file contains the function for asymmetric  key management
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

#include "Crypto_KeyManagement_Intern.h"
#include "Crypto_Keys.h"
#include "Crypto_ECDSA_Intern.h"
#include "Crypto_RSA_Intern.h"
#include "Crypto_Version.h"

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!Crypto_CHECK_VERSION(5,2,0))
#error "Version of Crypto_Keys.c does not match the version of the module!"
#endif

/*------------------------------------------------------------------------------
                      Local Variables
------------------------------------------------------------------------------*/

#define Crypto_START_SEC_CONST_UNSPECIFIED
#include "Crypto_MemMap.h"

/* ECDSA Entry */

#if  defined(CRYPTO_AUTH_KEY_LEVEL_3_X) && defined(CRYPTO_AUTH_KEY_LEVEL_3_Y) && defined(CRYPTO_AUTH_KEY_LEVEL_3_SIZE)
#if CRYPTO_AUTH_KEY_LEVEL_3_SIZE == 521 /* special case for P521 (doesn't fit into an uint32 ) */
  #undef  CRYPTO_AUTH_KEY_LEVEL_3_SIZE
  #define CRYPTO_AUTH_KEY_LEVEL_3_SIZE 544
#endif
  static const uint32 keyLevel3X[(CRYPTO_AUTH_KEY_LEVEL_3_SIZE/32)+1] =  CRYPTO_AUTH_KEY_LEVEL_3_X;
  static const uint32 keyLevel3Y[(CRYPTO_AUTH_KEY_LEVEL_3_SIZE/32)+1] =  CRYPTO_AUTH_KEY_LEVEL_3_Y;
  static const eccPublicKeyType keyLevel3 = {
          keyLevel3X,
          keyLevel3Y,
          CRYPTO_AUTH_KEY_LEVEL_3_SIZE/32
  };
#endif

#if defined(CRYPTO_AUTH_KEY_LEVEL_5_X) && defined(CRYPTO_AUTH_KEY_LEVEL_5_Y) && defined(CRYPTO_AUTH_KEY_LEVEL_5_SIZE)
#if CRYPTO_AUTH_KEY_LEVEL_5_SIZE == 521 /* special case for P521 (doesn't fit into an uint32 ) */
  #undef  CRYPTO_AUTH_KEY_LEVEL_5_SIZE
  #define CRYPTO_AUTH_KEY_LEVEL_5_SIZE 544
#endif
  static const uint32 keyLevel5X[(CRYPTO_AUTH_KEY_LEVEL_5_SIZE/32)+1] =  CRYPTO_AUTH_KEY_LEVEL_5_X;
  static const uint32 keyLevel5Y[(CRYPTO_AUTH_KEY_LEVEL_5_SIZE/32)+1] =  CRYPTO_AUTH_KEY_LEVEL_5_Y;
  static const eccPublicKeyType keyLevel5 = {
          keyLevel5X,
          keyLevel5Y,
          CRYPTO_AUTH_KEY_LEVEL_5_SIZE/32
  };
#endif

#if defined(CRYPTO_SIG_KEY_X) && defined(CRYPTO_SIG_KEY_Y) && defined(CRYPTO_SIG_KEY_SIZE)
  #if CRYPTO_SIG_KEY_SIZE == 521 /* special case for P521 (doesn't fit into an uint32 ) */
    #undef  CRYPTO_SIG_KEY_SIZE
    #define CRYPTO_SIG_KEY_SIZE 544
  #endif
  static const uint32 keySigAsymX[(CRYPTO_SIG_KEY_SIZE/32)+1] =  CRYPTO_SIG_KEY_X;
  static const uint32 keySigAsymY[(CRYPTO_SIG_KEY_SIZE/32)+1] =  CRYPTO_SIG_KEY_Y;
  static const eccPublicKeyType keySigAsym = {
          keySigAsymX,
          keySigAsymY,
          CRYPTO_SIG_KEY_SIZE/32
  };
#endif

#if defined(CRYPTO_NCD_KEY_X) && defined(CRYPTO_NCD_KEY_Y) && defined(CRYPTO_NCD_KEY_SIZE)
#if CRYPTO_NCD_KEY_SIZE == 521 /* special case for P521 (doesn't fit into an uint32 ) */
  #undef  CRYPTO_NCD_KEY_SIZE
  #define CRYPTO_NCD_KEY_SIZE 544
#endif
  static const uint32 keyNcdKeyX[(CRYPTO_NCD_KEY_SIZE/32)+1] =  CRYPTO_NCD_KEY_X;
  static const uint32 keyNcdKeyY[(CRYPTO_NCD_KEY_SIZE/32)+1] =  CRYPTO_NCD_KEY_Y;
  static const eccPublicKeyType keyNcdKey = {
          keyNcdKeyX,
          keyNcdKeyY,
          CRYPTO_NCD_KEY_SIZE / 32
  };
#endif

/* RSA Entry */

#if  defined(CRYPTO_AUTH_KEY_LEVEL_3_M) && defined(CRYPTO_AUTH_KEY_LEVEL_3_PE)
static const uint32 keyLevel3PE[(CRYPTO_AUTH_KEY_LEVEL_3_SIZE/32)+1] =  CRYPTO_AUTH_KEY_LEVEL_3_PE;
static const uint32 keyLevel3M [(CRYPTO_AUTH_KEY_LEVEL_3_SIZE/32)+1] =  CRYPTO_AUTH_KEY_LEVEL_3_M;
static const rsaPublicKeyType keyLevel3 = {
  keyLevel3PE,
  keyLevel3M,
  CRYPTO_AUTH_KEY_LEVEL_3_SIZE/32
};
#endif

#if  defined(CRYPTO_AUTH_KEY_LEVEL_5_M) && defined(CRYPTO_AUTH_KEY_LEVEL_5_PE)
static const uint32 keyLevel5PE[(CRYPTO_AUTH_KEY_LEVEL_5_SIZE/32)+1] =  CRYPTO_AUTH_KEY_LEVEL_5_PE;
static const uint32 keyLevel5M [(CRYPTO_AUTH_KEY_LEVEL_5_SIZE/32)+1] =  CRYPTO_AUTH_KEY_LEVEL_5_M;
static const rsaPublicKeyType keyLevel5 = {
  keyLevel5PE,
  keyLevel5M,
  CRYPTO_AUTH_KEY_LEVEL_5_SIZE/32
};
#endif

#if  defined(CRYPTO_SIG_KEY_M) && defined(CRYPTO_SIG_KEY_PE)
static const uint32 keySigAsymPE[(CRYPTO_SIG_KEY_SIZE/32)+1] =  CRYPTO_SIG_KEY_PE;
static const uint32 keySigAsymM [(CRYPTO_SIG_KEY_SIZE/32)+1] =  CRYPTO_SIG_KEY_M;
static const rsaPublicKeyType keySigAsym = {
  keySigAsymPE,
  keySigAsymM,
  CRYPTO_SIG_KEY_SIZE/32
};
#endif


#if  defined(CRYPTO_NCD_KEY_M) && defined(CRYPTO_NCD_KEY_PE)
static const uint32 keyNcdPE[(CRYPTO_NCD_KEY_SIZE/32)+1] =  CRYPTO_NCD_KEY_PE;
static const uint32 keyNcdM [(CRYPTO_NCD_KEY_SIZE/32)+1] =  CRYPTO_NCD_KEY_M;
static const rsaPublicKeyType keyNcdKey = {
  keyNcdPE,
  keyNcdM,
  CRYPTO_NCD_KEY_SIZE/32
};
#endif

static const publicKeyType publicKeysTable[] = {
#if  defined(CRYPTO_AUTH_KEY_LEVEL_3_SIZE)
  {
    &keyLevel3,
    #if defined(CRYPTO_AUTH_KEY_LEVEL_3_M) && defined(CRYPTO_AUTH_KEY_LEVEL_3_PE)
    PK_RSA
    #elif defined(CRYPTO_AUTH_KEY_LEVEL_3_X) && defined(CRYPTO_AUTH_KEY_LEVEL_3_Y)
    PK_ECDSA
    #else
      #error "incorrect Crypto_Keys header file"
    #endif
  },
#endif
#if  defined(CRYPTO_AUTH_KEY_LEVEL_5_SIZE)
  {
    &keyLevel5,
#if defined(CRYPTO_AUTH_KEY_LEVEL_5_M) && defined(CRYPTO_AUTH_KEY_LEVEL_5_PE)
    PK_RSA
#elif defined(CRYPTO_AUTH_KEY_LEVEL_5_X) && defined(CRYPTO_AUTH_KEY_LEVEL_5_Y)
    PK_ECDSA
#else
#error "incorrect Crypto_Keys header file"
#endif
  },
#endif
#if  defined(CRYPTO_SIG_KEY_SIZE)
  {
    &keySigAsym,
#if defined(CRYPTO_SIG_KEY_M) && defined(CRYPTO_SIG_KEY_PE)
    PK_RSA
#elif defined(CRYPTO_SIG_KEY_X) && defined(CRYPTO_SIG_KEY_Y)
    PK_ECDSA
#else
#error "incorrect Crypto_Keys header file"
#endif
  },
#endif
#if  defined(CRYPTO_NCD_KEY_SIZE)
  {
    &keyNcdKey,
#if defined(CRYPTO_NCD_KEY_M) && defined(CRYPTO_NCD_KEY_PE)
    PK_RSA
#elif defined(CRYPTO_NCD_KEY_X) && defined(CRYPTO_NCD_KEY_Y)
    PK_ECDSA
#else
#error "incorrect Crypto_Keys header file"
#endif
  },
#endif
  NULL
};

#define Crypto_STOP_SEC_CONST_UNSPECIFIED
#include "Crypto_MemMap.h"

/*------------------------------------------------------------------------------
                      Local Functions
------------------------------------------------------------------------------*/

static void Crypto_getEccKeyByIndex(ecc_point* targetKey,  const  eccPublicKeyType* sourceKey);
static void Crypto_getRSAKeyByIndex(rsa_key* targetKey, const rsaPublicKeyType* sourceKey);

/*------------------------------------------------------------------------------
                      Local Functions
------------------------------------------------------------------------------*/

#define Crypto_START_SEC_CODE
#include "Crypto_MemMap.h"

static void Crypto_getEccKeyByIndex(ecc_point* targetKey,const eccPublicKeyType* sourceKey )
{
  /* Reading coordinate X */
  mp_read_unsigned_bin_uint32_LE(targetKey->x, (uint32 *) &(sourceKey->keyX[1]),
                                 (uint16)sourceKey->keyX[0]);
  /* Reading coordinate Y */
  mp_read_unsigned_bin_uint32_LE(targetKey->y, (uint32 *) &(sourceKey->keyY[1]),
                                 (uint16)sourceKey->keyY[0]);
  /* Default value for z is always 1 */
  mp_set(targetKey->z, 1u);
}


static void Crypto_getRSAKeyByIndex(rsa_key* targetKey,const rsaPublicKeyType* sourceKey)
{
  /* Reading public exponent */
  mp_read_unsigned_bin_uint32_LE(targetKey->e, (uint32 *) &(sourceKey->pubExp[1]),
                                 (uint16)sourceKey->pubExp[0]);
  /* Reading modulus */
  mp_read_unsigned_bin_uint32_LE(targetKey->N, (uint32 *) &(sourceKey->modulus[1]),
                                 (uint16)sourceKey->modulus[0]);
  /* Setting key type to public. */
  targetKey->type = PK_PUBLIC;
}

/*------------------------------------------------------------------------------
                      Global Functions
------------------------------------------------------------------------------*/

/**
 * \brief  This function reads the global keyTable and returns the desired key in the correct format.
 *
 * \global_r  --
 * \global_w  --
 * \global_rw --
 *
 * \param[in]     keyIndex  Index number to the public key.
 * \param[out]    publicKey pointer to the public key to find.
 * \param[out]    keyType   Type of the key (e.g: RSA).
 *
 * \returns  Error value.
 *
 * \retval   CRYPTO_E_OK   Request successful
 * \retval   CRYPTO_E_NOK  Request failed
 *
 * \pre the pointer must be set (i.e. not null)
 *
 * \post --
 *
 * \serviceid
 * \reentrancy Reentrant
 *
 */

Crypto_ReturnType Crypto_getKeybyIndex(void* publicKey, uint8 keyIndex, keyType_t keyType)
{
  Crypto_ReturnType error;
  error = CRYPTO_E_NOK;

  /* Checking if the key exists, is not NULL and is of the right type */
  if( ((sizeof(publicKeysTable)/ sizeof(publicKeysTable[0]) ) > keyIndex) &&
      ( publicKeysTable[keyIndex].key != NULL )) {
    /* if the key is not the same type as what was expected, return CRYPTO_E_NOK  */
    if(publicKeysTable[keyIndex].keyType == keyType){
      error = CRYPTO_E_OK;

      switch (publicKeysTable[keyIndex].keyType)
      {
        case PK_RSA :
          Crypto_getRSAKeyByIndex(publicKey, publicKeysTable[keyIndex].key);
          break;
        case PK_ECDSA :
          Crypto_getEccKeyByIndex(publicKey, publicKeysTable[keyIndex].key);
          break;
        default :
          /* this line should never be reached */
          error = CRYPTO_E_NOK;
          break;
      }
    }
  }
  return error;
}


/**
 * \brief  This function gets a byte array and format it as an usable key for signature verification .
 *
 * \global_r  --
 * \global_w  --
 * \global_rw --
 *
 * \param[in]     inputData the input for the creation of the key.
 * \param[out]    targetKey the target formatted key.
 *
 * \pre the pointer must be set and the corresponding structure for the key must be allocated.
 *
 * \post --
 *
 * \remarks TBD
 *
 * \serviceid
 * \reentrancy Reentrant
 *
 */

void Crypto_makeECDSAKeyStruct(eccPublicKeyStruct *inputData, ecc_key *targetKey) {
  /* Reading coordinate X */
  mp_read_unsigned_bin(targetKey->pubkey.x, inputData->pubKeyX , inputData->length);
  /* Reading coordinate Y */
  mp_read_unsigned_bin(targetKey->pubkey.y, inputData->pubKeyY , inputData->length);
  /* Default value for z is always 1 */
  mp_set(targetKey->pubkey.z , 1u);
}


#define Crypto_STOP_SEC_CODE
#include "Crypto_MemMap.h"