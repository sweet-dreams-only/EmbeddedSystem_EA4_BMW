/**
*  \file
*
*  \brief       BMW Crypto Library
*
*  This file is the main header file of the generic part of the Crypto lib
*  for usage in the BMW AUTOSAR Core.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.2.0
*
*/


#ifndef CRYPTO_COMMON_INTERN_H
#define CRYPTO_COMMON_INTERN_H

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/


#include <stddef.h>
#include "BUtil/PlatformTypes.h"
#include "Crypto_Types.h"
#include "Crypto.h"
#include "Crypto_Version.h"


#ifdef __cplusplus
extern  "C" {
#endif

/*------------------------------------------------------------------------------
                              Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!Crypto_CHECK_VERSION(5,2,0))
#error "Version of Crypto_Common_Intern.h does not match the version of the module!"
#endif

/** math functions **/

#define LTC_MP_LT   FP_LT /* less than    */
#define LTC_MP_EQ   FP_EQ /* equal        */
#define LTC_MP_GT   FP_GT /* greater than */

/* TODO : this define should be configurable. */
#define MP_PREC

/* Key types  */
#define CRYPTO_ECDSA_KEY  1
#define CRYPTO_RSA_KEY    2

/*------------------------------------------------------------------------------
                      Data Types
------------------------------------------------------------------------------*/

typedef struct {
  /* hash name */
  sint8 name[30];
  /** internal ID */
  uint8 ID;
  /** Size of digest in octets */
  uint32 hashsize;
  /** Input block size in octets */
  uint32 blocksize;
  /* OID */
  uint32 OID[16];
  /* OID length */
  uint8 OIDlen;
  /* Hash init function  */
  void (*init) (hash_state *);
  /* Hash process function */
  Crypto_ReturnType (*process) (hash_state *, const uint8*, uint32);
  /* Hash done function */
  Crypto_ReturnType (*done)    (hash_state * md, uint8 *hash);
}hash_descriptor_t;

/*------------------------------------------------------------------------------
                      Global Variables
------------------------------------------------------------------------------*/

#define Crypto_START_SEC_CONST_UNSPECIFIED
#include "Crypto_MemMap.h"

/* hash descriptor */
extern const hash_descriptor_t hash_descriptor[3];

#define Crypto_STOP_SEC_CONST_UNSPECIFIED
#include "Crypto_MemMap.h"


/*------------------------------------------------------------------------------
                      Global Constants
------------------------------------------------------------------------------*/

/* Simple mapping is performed here. CRYPT_OK is used in Libtomcrypt and CRYPTO_E_OK         */
/* is used in the BMW Crypto library and is compliant to BMW naming convention.              */
/* Only CRYPT_OK needs to be mapped since the LTC functions only check if result!=CRYPT_OK.  */

#define CRYPT_OK CRYPTO_E_OK

/*------------------------------------------------------------------------------
                      Global Function Declarations
------------------------------------------------------------------------------*/

#define Crypto_START_SEC_CODE
#include "Crypto_MemMap.h"

/* ---- MEM routines ---- */
void  zeromem(volatile void *out, size_t outlen);
uint8 mem_neq(const void *a, const void *b, size_t len);
sint8 hash_is_valid(uint8 idx);

#define Crypto_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#ifdef __cplusplus
}
#endif



#endif /* CRYPTO_COMMON_INTERN_H */
