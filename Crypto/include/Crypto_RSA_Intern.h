/**
*  \file
*
*  \brief       BMW Crypto Library
*
*  This file is the header file of the ECDSA algorithm of the Crypto lib
*  for usage in the BMW AUTOSAR Core.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.2.0
*
*/



#ifndef PROJECT_CRYPTO_RSA_INTERN_H
#define PROJECT_CRYPTO_RSA_INTERN_H

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include <stddef.h>
#include "BUtil/PlatformTypes.h"
#include "Crypto_Types.h"
#include "Crypto_Common_Intern.h"
#include "Crypto_Math_Intern.h"
#include "BUtil_ByteMask.h"
#include "Crypto_Version.h"

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!Crypto_CHECK_VERSION(5,2,0))
#error "Version of Crypto_RSA_Intern.h does not match the version of the module!"
#endif

/* Mapping error code to Crypto_E_NOK since we don't need all these different errors */
#define CRYPT_PK_INVALID_PADDING CRYPTO_E_NOK
#define CRYPT_PK_NOT_PRIVATE     CRYPTO_E_NOK
#define CRYPT_INVALID_PACKET     CRYPTO_E_NOK
#define CRYPT_MEM                CRYPTO_E_NOK
#define CRYPT_PK_INVALID_TYPE    CRYPTO_E_NOK
#define CRYPT_BUFFER_OVERFLOW    CRYPTO_E_NOK
#define CRYPT_ERROR              CRYPTO_E_NOK
#define CRYPT_PK_INVALID_SIZE    CRYPTO_E_NOK


/* Mapping LTC functions to standard or BUtil functions  */
#define XMEMCPY(a,b,c) memcpy(a,b,c)
#define XMEM_NEQ  mem_neq
#define STORE32H(x, y) BUtil_Put32BitBigEndian(y,x)

/*------------------------------------------------------------------------------
                      Data Types
------------------------------------------------------------------------------*/

/** RSA PKCS style key */
typedef struct Rsa_key {
  /** Type of key, PK_PRIVATE or PK_PUBLIC */
  uint8 type;
  /** The public exponent */
  void *e;
  /** The private exponent */
  void *d;
  /** The modulus */
  void *N;
  /** The p factor of N */
  void *p;
  /** The q factor of N */
  void *q;
  /** The 1/q mod p CRT param */
  void *qP;
  /** The d mod (p - 1) CRT param */
  void *dP;
  /** The d mod (q - 1) CRT param */
  void *dQ;
} rsa_key;


#endif /* PROJECT_CRYPTO_RSA_INTERN_H */
