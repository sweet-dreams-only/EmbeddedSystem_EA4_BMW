/**
*  \file
*
*  \brief       Crypto module template
*
*  This file is the Crypto templace c file.
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

#include "Crypto_ECDSA_Intern.h"
#include "Crypto_KeyManagement_Intern.h"
#include "Crypto_Version.h"

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!Crypto_CHECK_VERSION(5,2,0))
#error "Version of Crypto_ECDSA.c does not match the version of the module!"
#endif

/* max size of either a cipher/hash block or symmetric key [largest of the two] */
/* current maximum - SHA512 (64bytes) */
#define MAXBLOCKSIZE  64


/*------------------------------------------------------------------------------
                      Local Variables
------------------------------------------------------------------------------*/

#ifdef __cplusplus
extern  "C" {
#endif

#define Crypto_START_SEC_CONST_UNSPECIFIED
#include "Crypto_MemMap.h"


static const struct
{
    uint32 size;
    uint32 prime[8];
    uint32 B[8];
    uint32 order[8];
    uint32 Gx[8];
    uint32 Gy[8];
}ecc256CurveData = {
        32u,
        {0xFFFFFFFFu, 0x00000001u, 0x00000000u, 0x00000000u, 0x00000000u, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu}, /* prime */
        {0x5AC635D8u, 0xAA3A93E7u, 0xB3EBBD55u, 0x769886BCu, 0x651D06B0u, 0xCC53B0F6u, 0x3BCE3C3Eu, 0x27D2604Bu}, /* B */
        {0xFFFFFFFFu, 0x00000000u, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xBCE6FAADu, 0xA7179E84u, 0xF3B9CAC2u, 0xFC632551u}, /* order */
        {0x6B17D1F2u, 0xE12C4247u, 0xF8BCE6E5u, 0x63A440F2u, 0x77037D81u, 0x2DEB33A0u, 0xF4A13945u, 0xD898C296u}, /* Gx */
        {0x4FE342E2u, 0xFE1A7F9Bu, 0x8EE7EB4Au, 0x7C0F9E16u, 0x2BCE3357u, 0x6B315ECEu, 0xCBB64068u, 0x37BF51F5u}  /* Gy */
};

static const struct
{
  uint32 size;
  uint32 prime[12];
  uint32 B[12];
  uint32 order[12];
  uint32 Gx[12];
  uint32 Gy[12];
}ecc384CurveData = {
        48u,
        {0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFEu, 0xFFFFFFFFu, 0x00000000u, 0x00000000u, 0xFFFFFFFFu}, /* prime */
        {0xB3312FA7u, 0xE23EE7E4u, 0x988E056Bu, 0xE3F82D19u, 0x181D9C6Eu, 0xFE814112u, 0x0314088Fu, 0x5013875Au, 0xC656398Du, 0x8A2ED19Du, 0x2A85C8EDu, 0xD3EC2AEFu}, /* B */
        {0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xC7634D81u, 0xF4372DDFu, 0x581A0DB2u, 0x48B0A77Au, 0xECEC196Au, 0xCCC52973u}, /* order */
        {0xAA87CA22u, 0xBE8B0537u, 0x8EB1C71Eu, 0xF320AD74u, 0x6E1D3B62u, 0x8BA79B98u, 0x59F741E0u, 0x82542A38u, 0x5502F25Du, 0xBF55296Cu, 0x3A545E38u, 0x72760AB7u}, /* Gx */
        {0x3617DE4Au, 0x96262C6Fu, 0x5D9E98BFu, 0x9292DC29u, 0xF8F41DBDu, 0x289A147Cu, 0xE9DA3113u, 0xB5F0B8C0u, 0x0A60B1CEu, 0x1D7E819Du, 0x7A431D7Cu, 0x90EA0E5Fu}  /* Gy */
};


static const struct
{
  uint32 size;
  uint32 prime[17];
  uint32 B[17];
  uint32 order[17];
  uint32 Gx[17];
  uint32 Gy[17];
}ecc521CurveData = {
        66u,
        {0x1FFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu},
        {0x51u , 0x953EB961u, 0x8E1C9A1Fu, 0x929A21A0u, 0xB68540EEu, 0xA2DA725Bu, 0x99B315F3u, 0xB8B48991u, 0x8EF109E1u, 0x56193951u, 0xEC7E937Bu, 0x1652C0BDu, 0x3BB1BF07u, 0x3573DF88u, 0x3D2C34F1u, 0xEF451FD4u, 0x6B503F00u},
        {0x1FFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFAu, 0x51868783u, 0xBF2F966Bu, 0x7FCC0148u, 0xF709A5D0u, 0x3BB5C9B8u, 0x899C47AEu, 0xBB6FB71Eu, 0x91386409u},
        {0xC6u , 0x858E06B7u, 0x0404E9CDu, 0x9E3ECB66u, 0x2395B442u, 0x9C648139u, 0x053FB521u, 0xF828AF60u, 0x6B4D3DBAu, 0xA14B5E77u, 0xEFE75928u, 0xFE1DC127u, 0xA2FFA8DEu, 0x3348B3C1u, 0x856A429Bu, 0xF97E7E31u, 0xC2E5BD66u},
        {0x118u, 0x39296A78u, 0x9A3BC004u, 0x5C8A5FB4u, 0x2C7D1BD9u, 0x98F54449u, 0x579B4468u, 0x17AFBD17u, 0x273E662Cu, 0x97EE7299u, 0x5EF42640u, 0xC550B901u, 0x3FAD0761u, 0x353C7086u, 0xA272C240u, 0x88BE9476u, 0x9FD16650u}
};


#define Crypto_STOP_SEC_CONST_UNSPECIFIED
#include "Crypto_MemMap.h"


/*------------------------------------------------------------------------------
                      Global Functions
------------------------------------------------------------------------------*/


#define Crypto_START_SEC_CODE
#include "Crypto_MemMap.h"


/**
 * \brief  This function extracts and builds the correct curve and the correct key to
 *         perform ecc verification.
 *
 * \global_r  --
 * \global_w  --
 * \global_rw --
 *
 *
 * \param[inout]  signature ECC "r" and "s" signature concatenated.
 * \param[in]     hash      The signed hash.
 * \param[in]     hashlen   Length of the hash that was signed (number of bytes).
 * \param[in]     keyIndex  Index number to the public key.
 * \param[out]    result    The result of the verification.
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
 * \remarks TBD
 *
 * \reentrancy Reentrant
 *
 * \lhref CERT_1011, CERT_1012, CERT_1015
 *
 */

Crypto_ReturnType Crypto_EccVerifyHash(
        const uint8* signature,     /* ECC signature (concatenated R and S) */
        size_t signatureLength,     /* Size of the signature in bytes */
        const uint8* hash,          /* Hashed data */
        size_t hashLength,          /* Size of the hash in bytes */
        uint8  keyIndex,            /* Index number to the public key */
        eccPublicKeyStruct *rawKey, /* non formatted public key */
        sint8  *result)             /* Result of the operation */

{
  mp_int             r, s, pubKeyX, pubKeyY, pubKeyZ, Gx_data, Gy_data;
  ecc_key            publicKey;
  Crypto_ReturnType  error;
  ltc_ecc_set_type   myECC;

  Crypto_mpInit(&r);
  Crypto_mpInit(&s);
  Crypto_mpInit(&pubKeyX);
  Crypto_mpInit(&pubKeyY);
  Crypto_mpInit(&pubKeyZ);

  /* Building the correct key structure according to the given index. */
  publicKey.pubkey.x = &pubKeyX;
  publicKey.pubkey.y = &pubKeyY;
  publicKey.pubkey.z = &pubKeyZ;


  /* if no key has been provided, we look for the key in the array. */
  if(rawKey == NULL )
  {
    error = Crypto_getKeybyIndex(&publicKey.pubkey, keyIndex, PK_ECDSA);
    if(error != CRYPTO_E_OK)
    {
      return error;
    }
  }else
  {
    Crypto_makeECDSAKeyStruct(rawKey, &publicKey);
  }

  /* Building the correct curve structure.  */
  Crypto_mpInit(&Gx_data);
  Crypto_mpInit(&Gy_data);
  Crypto_mpInit(&myECC.order);
  Crypto_mpInit(&myECC.prime);

  myECC.Gx = &Gx_data;
  myECC.Gy = &Gy_data;

  switch (signatureLength)
  {
    case 32u:
      /* Setting the ECC parameters to P-256. */
      mp_read_unsigned_bin_uint32(&myECC.prime, ecc256CurveData.prime , 8u );
      mp_read_unsigned_bin_uint32(&myECC.order, ecc256CurveData.order , 8u );
      mp_read_unsigned_bin_uint32(&Gx_data    , ecc256CurveData.Gx    , 8u );
      mp_read_unsigned_bin_uint32(&Gy_data    , ecc256CurveData.Gy    , 8u );
      break;

    case 48u:
      /* Setting the ECC parameters to P-384. */
      mp_read_unsigned_bin_uint32(&myECC.prime, ecc384CurveData.prime , 12u );
      mp_read_unsigned_bin_uint32(&myECC.order, ecc384CurveData.order , 12u );
      mp_read_unsigned_bin_uint32(&Gx_data    , ecc384CurveData.Gx    , 12u );
      mp_read_unsigned_bin_uint32(&Gy_data    , ecc384CurveData.Gy    , 12u );
      break;

    case 66u:
      /* Setting the ECC parameters to P-521. */
      mp_read_unsigned_bin_uint32(&myECC.prime, ecc521CurveData.prime , 17u );
      mp_read_unsigned_bin_uint32(&myECC.order, ecc521CurveData.order , 17u );
      mp_read_unsigned_bin_uint32(&Gx_data    , ecc521CurveData.Gx    , 17u );
      mp_read_unsigned_bin_uint32(&Gy_data    , ecc521CurveData.Gy    , 17u );
      break;

    default:
      /* Unsupported signature length (i.e. unsupported curve). */
      return  CRYPTO_E_NOK;
      break;
  }

  myECC.B = NULL;

  /* extract R and S */
  mp_read_unsigned_bin(&r, signature, signatureLength);
  mp_read_unsigned_bin(&s, signature + signatureLength, signatureLength);

  publicKey.dp = &myECC;

  /* calling the signature verification algorithm with correct parameters */
  error = ecc_verify_hash_raw(&r, &s, hash, hashLength, result, &publicKey);

  return error;
}



/**
 * \brief  This function performs the main algorithm of ECDSA signature verification
 *         This function shall be compatible with all (prime based) ECDSA curves.
 *
 * \global_r  --
 * \global_w  --
 * \global_rw --
 *
 *
 * \param[inout]  r         ECC "r" signature.
 * \param[in]     s         ECC "s" signature.
 * \param[in]     hash      The signed hash.
 * \param[in]     hashlen   Length of the hash that was signed (number of bytes).
 * \param[in]     key       The public DH key.
 * \param[out]    stat      the result of the verification.
 * \returns  Error value.
 *
 * \retval   CRYPTO_E_OK   verification successful (i.e. the verification has been performed).
 *
 * \pre the pointers must be set (i.e. not null)
 *
 * \post --
 *
 * \reentrancy Reentrant
 *
 */


/* verify
 *
 * w  = s^-1 mod n
 * u1 = xw
 * u2 = rw
 * X = u1*G + u2*Q
 * v = X_x1 mod n
 * accept if v == r
 */

sint8 ecc_verify_hash_raw(void   *r, void   *s,
                          const uint8 *hash, uint32 hashlen,
                          sint8 *stat, ecc_key *key)
{
  ecc_point    *mG, *mQ;
  ecc_point     mG_data, mQ_data;
  void          *v, *w, *u1, *u2, *e, *p, *m;
  mp_digit      mp;
  sint8         err;
  uint32        pbits,pbytes,i,shift_right;
  uint8         ch, buf[MAXBLOCKSIZE];

  /* no dynamic allocation. */
  mp_int        v_data, w_data, u1_data, u2_data, e_data, m_data, p_data;
  mp_int        mG_x, mG_y, mG_z;
  mp_int        mQ_x, mQ_y, mQ_z;

  /* default to invalid signature */
  *stat = CRYPTO_E_NOK;

  v  = & v_data ;
  w  = & w_data ;
  u1 = &u1_data ;
  u2 = &u2_data ;
  e  = & e_data ;
  m  = & m_data ;
  p  = & p_data ;

  Crypto_mpInit(v);
  Crypto_mpInit(w);
  Crypto_mpInit(u1);
  Crypto_mpInit(u2);
  Crypto_mpInit(e);
  Crypto_mpInit(p);
  Crypto_mpInit(m);
  Crypto_mpInit(&mG_x);
  Crypto_mpInit(&mG_y);
  Crypto_mpInit(&mG_z);
  Crypto_mpInit(&mQ_x);
  Crypto_mpInit(&mQ_y);
  Crypto_mpInit(&mQ_z);

  /* allocate points */
  mG_data.x = &mG_x;
  mG_data.y = &mG_y;
  mG_data.z = &mG_z;

  mQ_data.x = &mQ_x;
  mQ_data.y = &mQ_y;
  mQ_data.z = &mQ_z;

  mG = &mG_data;
  mQ = &mQ_data;

  /* get the order */
  mp_copy((mp_int*)&key->dp->order, p );

  /* get the modulus */
  mp_copy((mp_int*)&key->dp->prime, m);

  /* check for zero */
  if (mp_iszero((mp_int*)r) || mp_iszero((mp_int*)s) || mp_cmp(r, p) != LTC_MP_LT || mp_cmp(s, p) != LTC_MP_LT) {
    err = CRYPTO_E_NOK;
    goto error;
  }

  /* read hash - truncate if needed */
  pbits = fp_count_bits(p);
  pbytes = (pbits+7) >> 3;
  if (pbits > hashlen*8) {
    mp_read_unsigned_bin(e, (unsigned char *)hash, hashlen);
  }
  else if (pbits % 8 == 0) {
    mp_read_unsigned_bin(e, (unsigned char *)hash, pbytes);
  }
  else {
    shift_right = 8 - pbits % 8;
    for (i=0, ch=0; i<pbytes; i++) {
      buf[i] = ch;
      ch = (hash[i] << (8-shift_right));
      buf[i] = buf[i] ^ (hash[i] >> shift_right);
    }
    mp_read_unsigned_bin(e, (unsigned char *)buf, pbytes);
  }

  /*  w  = s^-1 mod n */
  if ((err = mp_invmod(s, p, w)) != CRYPT_OK)                                                          { goto error; }

  /* u1 = ew */
  if ((err = mp_mulmod(e, w, p, u1)) != CRYPT_OK)                                                      { goto error; }

  /* u2 = rw */
  if ((err = mp_mulmod(r, w, p, u2)) != CRYPT_OK)                                                      { goto error; }

  /* find mG and mQ */
  mp_copy(key->dp->Gx, mG->x);
  mp_copy(key->dp->Gy, mG->y);

  mp_set(mG->z, 1);

  mp_copy(key->pubkey.x, mQ->x);
  mp_copy(key->pubkey.y, mQ->y);
  mp_copy(key->pubkey.z, mQ->z);

  /* compute u1*mG + u2*mQ = mG */

#ifndef USING_SHAMIRS_TRICK
    if ((err = ltc_ecc_mulmod(u1, mG, mG, m, 0)) != CRYPT_OK)                                         { goto error; }
    if ((err = ltc_ecc_mulmod(u2, mQ, mQ, m, 0)) != CRYPT_OK)                                         { goto error; }

    /* find the montgomery mp */
    if ((err = mp_montgomery_setup(m, &mp)) != CRYPT_OK)                                              { goto error; }

    /* add them */
    if ((err = ltc_ecc_projective_add_point(mQ, mG, mG, m, &mp)) != CRYPT_OK)                          { goto error; }

    /* reduce */
    if ((err = ltc_ecc_map(mG, m, &mp)) != CRYPT_OK)                                                   { goto error; }
#else
    /* use Shamir's trick to compute u1*mG + u2*mQ using half of the doubles */
    if ((err = ltc_ecc_mul2add(mG, u1, mQ, u2, mG, m)) != CRYPT_OK)                                { goto error; }
#endif

  /* v = X_x1 mod n */
  if ((err = mp_mod(mG->x, p, v)) != CRYPT_OK)                                                      { goto error; }

  /* does v == r */
  if (mp_cmp(v, r) == LTC_MP_EQ) {
    *stat = CRYPTO_E_OK;
  }

  /* clear up and return */
  err = CRYPTO_E_OK;
  error:
  return err;
}


#define Crypto_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#ifdef __cplusplus
}
#endif
