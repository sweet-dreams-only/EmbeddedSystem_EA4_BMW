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


#ifndef CRYPTO_ECDSA_INTERN_H
#define CRYPTO_ECDSA_INTERN_H


/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include <stddef.h>
#include "BUtil/PlatformTypes.h"
#include "Crypto_Types.h"
#include "Crypto_Common_Intern.h"
#include "Crypto_Math_Intern.h"
#include "Crypto_Version.h"



#ifdef __cplusplus
extern  "C" {
#endif

/*------------------------------------------------------------------------------
                              Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!Crypto_CHECK_VERSION(5,2,0))
#error "Version of Crypto_ECDSA_Intern.h does not match the version of the module!"
#endif


/*------------------------------------------------------------------------------
                      Data Types
------------------------------------------------------------------------------*/


typedef struct {
  /** The size of the curve in octets */
  uint32 size;

  /** name of curve */
  uint8 *name;

  /** The prime that defines the field the curve is in (encoded in hex) */
  mp_int prime;

  /** The fields B param (hex) */
  uint8 *B;

  /** The order of the curve (hex) */
  mp_int order;

  /** The x co-ordinate of the base point on the curve (hex) */
  void *Gx;

  /** The y co-ordinate of the base point on the curve (hex) */
  void *Gy;
} ltc_ecc_set_type;

/** A point on a ECC curve, stored in Jacbobian format such that (x,y,z) => (x/z^2, y/z^3, 1) when interpretted as affine */
typedef struct {
  /** The x co-ordinate */
  void *x;

  /** The y co-ordinate */
  void *y;

  /** The z co-ordinate */
  void *z;
} ecc_point;

/* An ECC KEY */
typedef struct {
  /** Type of key, PK_PRIVATE or PK_PUBLIC */
  uint8 type;

  /** Index into the ltc_ecc_sets[] for the parameters of this curve; if -1, then this key is using user supplied curve in dp */
  sint8 idx;

  /** pointer to domain parameters; either points to NIST curves (identified by idx >= 0) or user supplied curve */
  const ltc_ecc_set_type *dp;

  /** The public key */
  ecc_point pubkey;

  /** The private key */
  void *k;
} ecc_key;


/*------------------------------------------------------------------------------
                      Global Variables
------------------------------------------------------------------------------*/




/*------------------------------------------------------------------------------
                      Global Function Declarations
------------------------------------------------------------------------------*/

sint8 ltc_ecc_projective_dbl_point(ecc_point *P, ecc_point *R, void *modulus, mp_digit *mp);

sint8 ltc_ecc_projective_add_point(ecc_point *P, ecc_point *Q, ecc_point *R, void *modulus, mp_digit *mp);

sint8 ltc_ecc_map(ecc_point *P, void *modulus, mp_digit *mp);

sint8 ltc_ecc_mulmod(mp_int *k, ecc_point *G, ecc_point *R, void *modulus, sint32 map);

sint8 ecc_verify_hash_raw(void   *r, void   *s,
                          const uint8 *hash, uint32 hashlen,
                          sint8 *stat, ecc_key *key);

Crypto_ReturnType ltc_ecc_mul2add(ecc_point *A, void *kA,
                    ecc_point *B, void *kB,
                    ecc_point *C,
                    void *modulus);

#ifdef __cplusplus
}
#endif



#endif /* CRYPTO_ECDSA_INTERN_H */
