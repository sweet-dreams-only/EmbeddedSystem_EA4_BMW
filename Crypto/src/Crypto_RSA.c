/**
*  \file
*
*  \brief       Crypto module template
*
*  This file contains the RSA routine of the BMW crypto library.
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

#include "Crypto_RSA_Intern.h"
#include "Crypto_KeyManagement_Intern.h"
#include "Crypto_Version.h"

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!Crypto_CHECK_VERSION(5,2,0))
#error "Version of Crypto_RSA.c does not match the version of the module!"
#endif

/*------------------------------------------------------------------------------
                      Local Functions Prototypes
------------------------------------------------------------------------------*/
#define Crypto_START_SEC_CODE
#include "Crypto_MemMap.h"


static sint8 rsa_exptmod(const uint8 *in, uint32 inlen,
                         uint8 *out, uint32 *outlen,
                         uint8 which, rsa_key *key);

static sint8 pkcs_1_pss_decode(const uint8 *msghash,
                               uint32 msghashlen,
                               const uint8 *sig,
                               uint32 siglen,
                               uint32 saltlen,
                               uint8 hash_idx,
                               uint32 modulus_bitlen,
                               sint8 *res);

static sint8 pkcs_1_mgf1(uint8 hash_idx,
                         const uint8 *seed,
                         uint32 seedlen,
                         uint8 *mask,
                         uint32 masklen);


static Crypto_ReturnType rsa_verify_hash_ex(const uint8 *sig, uint32 siglen,
                                const uint8 *hash, uint32 hashlen,
                                uint8 padding,
                                hashAlgorithmIndex hash_idx,
                                uint32 saltlen,
                                sint8 *stat,
                                rsa_key *key);


/*------------------------------------------------------------------------------
                      Local Functions
------------------------------------------------------------------------------*/



/**
  PKCS #1 de-sign then v1.5 or PSS depad
  \param sig              The signature data
  \param siglen           The length of the signature data (octets)
  \param hash             The hash of the message that was signed
  \param hashlen          The length of the hash of the message that was signed (octets)
  \param padding          Type of padding (LTC_PKCS_1_PSS, LTC_PKCS_1_V1_5 or LTC_PKCS_1_V1_5_NA1)
  \param hash_idx         The index of the desired hash
  \param saltlen          The length of the salt used during signature
  \param stat             [out] The result of the signature comparison, 1==valid, 0==invalid
  \param key              The public RSA key corresponding to the key that performed the signature
  \return CRYPT_OK on success (even if the signature is invalid)
*/
static Crypto_ReturnType rsa_verify_hash_ex(const uint8   *sig,      uint32 siglen,
                         const uint8   *hash,     uint32 hashlen,
                         uint8    padding,
                         hashAlgorithmIndex    hash_idx,
                         uint32   saltlen,
                         sint8    *stat,
                         rsa_key *key)
{
  uint32 modulus_bitlen, modulus_bytelen, x;
  Crypto_ReturnType  err;
  uint8  tmpbuf[MAX_SIGNATURE_LENGTH_IN_BYTES];

  /* default to invalid */
  *stat = CRYPTO_E_NOK;

  /* valid padding? */

  if (padding != LTC_PKCS_1_PSS)
  {
    return CRYPT_PK_INVALID_PADDING;
  }
  /* following code shall not be used. */
#ifdef USING_PKCS1_V15
  if (padding != LTC_PKCS_1_V1_5_NA1) {
    /* valid hash ? */
    if ((err = hash_is_valid(hash_idx)) != CRYPT_OK) {
       return err;
    }
  }
#endif
  /* get modulus len in bits */
  modulus_bitlen = mp_count_bits( (key->N));

  /* outlen must be at least the size of the modulus */
  modulus_bytelen = mp_unsigned_bin_size( (key->N));
  if (modulus_bytelen != siglen) {
    return CRYPT_INVALID_PACKET;
  }

  /* RSA decode it  */
  x = siglen;
  if ((err = (Crypto_ReturnType) rsa_exptmod(sig, siglen, tmpbuf, &x, PK_PUBLIC, key)) != CRYPT_OK) {
    return err;
  }

  /* make sure the output is the right size */
  if (x != siglen) {
    return CRYPT_INVALID_PACKET;
  }

  if (padding == LTC_PKCS_1_PSS) {
    /* PSS decode and verify it */

    if(modulus_bitlen%8 == 1){
      err = pkcs_1_pss_decode(hash, hashlen, tmpbuf+1, x-1, saltlen, hash_idx, modulus_bitlen, stat);
    }
    else{
      err = pkcs_1_pss_decode(hash, hashlen, tmpbuf, x, saltlen, hash_idx, modulus_bitlen, stat);
    }

  }

  else {
    /* PKCS #1 v1.5 decode it          */
    /* ToDO : add PKCS V1.5 management */
    err = CRYPTO_E_NOK;
  }
#ifdef LTC_CLEAN_STACK
  zeromem(tmpbuf, siglen);
#endif

  return err;
}

/**
   \brief Perform PKCS #1 MGF1 (internal)
   \param hash_idx    The index of the hash desired
   \param seed        The seed for MGF1
   \param seedlen     The length of the seed
   \param mask        [out] The destination
   \param masklen     The length of the mask desired
   \return CRYPT_OK if successful
*/
static sint8 pkcs_1_mgf1(uint8 hash_idx,
                  const uint8 *seed,
                  uint32 seedlen,
                  uint8 *mask,
                  uint32 masklen)
{
  uint32     hLen, x;
  uint32     counter;
  sint8      err;
  hash_state md;
  uint8      buf[64];

  /* ensure valid hash */
  if ((err = hash_is_valid(hash_idx)) != CRYPT_OK) {
    return err;
  }

  /* get hash output size */
  hLen = hash_descriptor[hash_idx].hashsize;

  /* start counter */
  counter = 0;

  while (masklen > 0) {
    /* handle counter */
    STORE32H(counter, buf);
    ++counter;

    /* get hash of seed || counter */
    hash_descriptor[hash_idx].init(&md);
    if ((err = hash_descriptor[hash_idx].process(&md, seed, seedlen)) != CRYPT_OK) {
      goto LBL_ERR;
    }
    if ((err = hash_descriptor[hash_idx].process(&md, buf, 4)) != CRYPT_OK) {
      goto LBL_ERR;
    }
    if ((err = hash_descriptor[hash_idx].done(&md, buf)) != CRYPT_OK) {
      goto LBL_ERR;
    }

    /* store it */
    for (x = 0; x < hLen && masklen > 0; x++, masklen--) {
      *mask++ = buf[x];
    }
  }

  err = CRYPT_OK;
  LBL_ERR:
#ifdef LTC_CLEAN_STACK
  zeromem(buf, hLen);
  zeromem(md, sizeof(hash_state));
#endif

  return err;
}

/**
   \brief PKCS #1 v2.00 PSS decode
   \param  msghash         The hash to verify
   \param  msghashlen      The length of the hash (octets)
   \param  sig             The signature data (encoded data)
   \param  siglen          The length of the signature data (octets)
   \param  saltlen         The length of the salt used (octets)
   \param  hash_idx        The index of the hash desired
   \param  modulus_bitlen  The bit length of the RSA modulus
   \param  res             [out] The result of the comparison, 1==valid, 0==invalid
   \return CRYPT_OK if successful (even if the comparison failed)
*/
static sint8 pkcs_1_pss_decode(const uint8   *msghash,
                        uint32        msghashlen,
                        const uint8   *sig,
                        uint32        siglen,
                        uint32        saltlen,
                        uint8         hash_idx,
                        uint32        modulus_bitlen,
                        sint8         *res)
{
  uint8 DB[MAX_SIGNATURE_LENGTH_IN_BYTES], mask[MAX_SIGNATURE_LENGTH_IN_BYTES], hash[MAX_SIGNATURE_LENGTH_IN_BYTES];
  uint32 x, y, hLen, modulus_len;
  sint8 err;
  hash_state    md;

  /* default to invalid */
  *res = CRYPTO_E_NOK;

  /* ensure hash is valid */
  if ((err = hash_is_valid(hash_idx)) != CRYPT_OK) {
    return err;
  }

  hLen        = hash_descriptor[hash_idx].hashsize;
  modulus_bitlen--;
  modulus_len = (modulus_bitlen>>3) + (modulus_bitlen & 7 ? 1 : 0);

  /* check sizes */
  if ((saltlen > modulus_len) ||
      (modulus_len < hLen + saltlen + 2)) {
    return CRYPT_PK_INVALID_SIZE;
  }


  /* ensure the 0xBC byte */
  if (sig[siglen-1] != 0xBC) {
    err = CRYPT_INVALID_PACKET;
    goto LBL_ERR;
  }

  /* copy out the DB */
  x = 0;
  XMEMCPY(DB, sig + x, modulus_len - hLen - 1);
  x += modulus_len - hLen - 1;

  /* copy out the hash */
  XMEMCPY(hash, sig + x, hLen);
  /* x += hLen; */

  /* check the MSB */
  if ((sig[0] & ~(0xFF >> ((modulus_len<<3) - (modulus_bitlen)))) != 0) {
    err = CRYPT_INVALID_PACKET;
    goto LBL_ERR;
  }

  /* generate mask of length modulus_len - hLen - 1 from hash */
  if ((err = pkcs_1_mgf1(hash_idx, hash, hLen, mask, modulus_len - hLen - 1)) != CRYPT_OK) {
    goto LBL_ERR;
  }

  /* xor against DB */
  for (y = 0; y < (modulus_len - hLen - 1); y++) {
    DB[y] ^= mask[y];
  }

  /* now clear the first byte [make sure smaller than modulus] */
  DB[0] &= 0xFF >> ((modulus_len<<3) - (modulus_bitlen));

  /* DB = PS || 0x01 || salt, PS == modulus_len - saltlen - hLen - 2 zero bytes */

  /* check for zeroes and 0x01 */
  for (x = 0; x < modulus_len - saltlen - hLen - 2; x++) {
    if (DB[x] != 0x00) {
      err = CRYPT_INVALID_PACKET;
      goto LBL_ERR;
    }
  }

  /* check for the 0x01 */
  if (DB[x++] != 0x01) {
    err = CRYPT_INVALID_PACKET;
    goto LBL_ERR;
  }

  /* M = (eight) 0x00 || msghash || salt, mask = H(M) */
  hash_descriptor[hash_idx].init(&md);
  zeromem(mask, 8);
  if ((err = hash_descriptor[hash_idx].process(&md, mask, 8)) != CRYPT_OK) {
    goto LBL_ERR;
  }
  if ((err = hash_descriptor[hash_idx].process(&md, msghash, msghashlen)) != CRYPT_OK) {
    goto LBL_ERR;
  }
  if ((err = hash_descriptor[hash_idx].process(&md, DB+x, saltlen)) != CRYPT_OK) {
    goto LBL_ERR;
  }
  if ((err = hash_descriptor[hash_idx].done(&md, mask)) != CRYPT_OK) {
    goto LBL_ERR;
  }

  /* mask == hash means valid signature */
  if (XMEM_NEQ(mask, hash, hLen) == 0) {
    *res = CRYPTO_E_OK;
  }

  err = CRYPT_OK;
  LBL_ERR:
#ifdef LTC_CLEAN_STACK
  zeromem(DB,   modulus_len);
   zeromem(mask, modulus_len);
   zeromem(salt, modulus_len);
   zeromem(hash, modulus_len);
#endif

  return err;
}


/**
 *  \brief Compute an RSA modular exponentiation
 *  \param in         The input data to send into RSA
 *  \param inlen      The length of the input (octets)
 *  \param out        [out] The destination
 *  \param outlen     [in/out] The max size and resulting size of the output
 *  \param which      Which exponent to use, e.g. PK_PRIVATE or PK_PUBLIC
 *  \param key        The RSA key to use
 *  \return CRYPT_OK if successful
*/
static sint8 rsa_exptmod(const uint8* in,    uint32 inlen,
                  uint8 *out, uint32 *outlen,
                  uint8 which, rsa_key *key)
{
  void        *tmp, *tmpa, *tmpb;
#ifdef LTC_RSA_BLINDING
  void        *rnd, *rndi /* inverse of rnd */;
#endif
  uint32 x;
  sint32 has_crt_parameters;
  sint8  err;
  /* static allocation */
  mp_int      tmp_data, tmpa_data, tmpb_data;
  tmpa =&tmpa_data;
  tmpb =&tmpb_data;
  tmp  =&tmp_data;


  /* is the key of the right type for the operation? */
  if (which == PK_PRIVATE && (key->type != PK_PRIVATE)) {
    return CRYPT_PK_NOT_PRIVATE;
  }

  /* must be a private or public operation */
  if (which != PK_PRIVATE && which != PK_PUBLIC) {
    return CRYPT_PK_INVALID_TYPE;
  }

  /* init and copy into tmp */
  fp_init(tmp);
  fp_init(tmpa);
  fp_init(tmpb);
#ifdef LTC_RSA_BLINDING
  fp_init(&rnd);
  fp_init(&rndi);
#endif /* LTC_RSA_BLINDING */


  mp_read_unsigned_bin(tmp, (uint8 *)in, (sint32)inlen);

  /* sanity check on the input */
  if (mp_cmp(key->N, tmp) == LTC_MP_LT) {
    err = CRYPT_PK_INVALID_SIZE;
    goto error;
  }

  /* are we using the private exponent and is the key optimized? */
  if (which == PK_PRIVATE) {
#ifdef LTC_RSA_BLINDING
    /* do blinding */
      err = mp_rand(rnd, mp_get_digit_count(key->N));
      if (err != CRYPT_OK) {
             goto error;
      }

      /* rndi = 1/rnd mod N */
      err = mp_invmod(rnd, key->N, rndi);
      if (err != CRYPT_OK) {
             goto error;
      }

      /* rnd = rnd^e */
      err = mp_exptmod( rnd, key->e, key->N, rnd);
      if (err != CRYPT_OK) {
             goto error;
      }

      /* tmp = tmp*rnd mod N */
      err = mp_mulmod( tmp, rnd, key->N, tmp);
      if (err != CRYPT_OK) {
             goto error;
      }
#endif /* LTC_RSA_BLINDING */

    has_crt_parameters = (key->p != NULL) && (mp_get_digit_count(key->p) != 0) &&
                         (key->q != NULL) && (mp_get_digit_count(key->q) != 0) &&
                         (key->dP != NULL) && (mp_get_digit_count(key->dP) != 0) &&
                         (key->dQ != NULL) && (mp_get_digit_count(key->dQ) != 0) &&
                         (key->qP != NULL) && (mp_get_digit_count(key->qP) != 0);

    if (!has_crt_parameters) {
      /*
       * In case CRT optimization parameters are not provided,
       * the private key is directly used to exptmod it
       */
      if ((err = mp_exptmod(tmp, key->d, key->N, tmp)) != CRYPT_OK)                              { goto error; }
    } else {
      /* tmpa = tmp^dP mod p */
      if ((err = mp_exptmod(tmp, key->dP, key->p, tmpa)) != CRYPT_OK)                            { goto error; }

      /* tmpb = tmp^dQ mod q */
      if ((err = mp_exptmod(tmp, key->dQ, key->q, tmpb)) != CRYPT_OK)                            { goto error; }

      /* tmp = (tmpa - tmpb) * qInv (mod p) */
      mp_sub(tmpa, tmpb, tmp);
      if ((err = mp_mulmod(tmp, key->qP, key->p, tmp)) != CRYPT_OK)                              { goto error; }

      /* tmp = tmpb + q * tmp */
      mp_mul(tmp, key->q, tmp);
      mp_add(tmp, tmpb, tmp)  ;
    }

#ifdef LTC_RSA_BLINDING
    /* unblind */
      err = mp_mulmod( tmp, rndi, key->N, tmp);
      if (err != CRYPT_OK) {
             goto error;
      }
#endif

#ifdef LTC_RSA_CRT_HARDENING
    if (has_crt_parameters) {
         if ((err = mp_exptmod(tmp, key->e, key->N, tmpa)) != CRYPT_OK)                              { goto error; }
         if ((err = mp_read_unsigned_bin(tmpb, (unsigned char *)in, (int)inlen)) != CRYPT_OK)        { goto error; }
         if (mp_cmp(tmpa, tmpb) != LTC_MP_EQ)                                     { err = CRYPT_ERROR; goto error; }
      }
#endif
  } else {
    /* exptmod it */
    if ((err = mp_exptmod(tmp, key->e, key->N, tmp)) != CRYPT_OK)                                { goto error; }
  }

  /* read it back */
  x = (uint32)mp_unsigned_bin_size(key->N);
  if (x > *outlen) {
    *outlen = x;
    err = CRYPT_BUFFER_OVERFLOW;
    goto error;
  }

  /* this should never happen ... */
  if (mp_unsigned_bin_size(tmp) > mp_unsigned_bin_size(key->N)) {
    err = CRYPT_ERROR;
    goto error;
  }
  *outlen = x;

  /* convert it */
  zeromem(out, x);
  mp_to_unsigned_bin(tmp, out+(x-mp_unsigned_bin_size(tmp)));

  /* clean up and return */
  err = CRYPT_OK;
  error:

  return err;
}


/*------------------------------------------------------------------------------
                      Global Functions
------------------------------------------------------------------------------*/

/**
* \brief PKCS #1 de-sign and verify
*
* \param signature        The signature data
* \param signatureLength  The length of the signature data (octets)
* \param hash             The hash of the message that was signed
* \param hashLength       The length of the hash of the message that was signed (octets)
* \param padding          Type of padding (LTC_PKCS_1_PSS, LTC_PKCS_1_V1_5 or LTC_PKCS_1_V1_5_NA1)
* \param hashingIndex     The index of the desired hash
* \param saltlen          The length of the salt used during signature
* \param result           [out] The result of the signature comparison, CRYPTO_E_OK ==valid, CRYPTO_E_NOK ==invalid
* \param keyIndex         The public RSA key corresponding to the key that performed the signature
* \param rawKey           The non formatted key to use for this operation (if equal to NULL, we shall use the index instead).
*
* \return CRYPT_OK on success (even if the signature is invalid)
*/



Crypto_ReturnType Crypto_RsaVerifyHash(
  const uint8* signature,         /* RSA signature */
  uint32 signatureLength,         /* Size of the signature in bytes */
  const uint8* hash,              /* Hashed data */
  uint32 hashLength,              /* Size of the hash in bytes */
  uint8 padding,                  /* padding type */
  hashAlgorithmIndex hashingIndex,/* type of hashing used */
  uint32 saltlen,                 /* size of salt */
  uint8 keyIndex,                 /* Index number to the public key */
  rsaPublicKeyStruct *rawKey,     /* non formatted public key */
  sint8  *result)                 /* Result of the operation */
{

  rsa_key publicKey;
  mp_int pubExp, mod;
  Crypto_ReturnType error;

  /* defining key */
  publicKey.type = PK_PUBLIC;
  /** The public exponent */
  publicKey.e  = &pubExp;
  /** The private exponent */
  publicKey.d  = NULL;
  /** The modulus */
  publicKey.N  = &mod;
  /** The p factor of N */
  publicKey.p  = NULL;
  /** The q factor of N */
  publicKey.q  = NULL;
  /** The 1/q mod p CRT param */
  publicKey.qP = NULL;
  /** The d mod (p - 1) CRT param */
  publicKey.dP = NULL;
  /** The d mod (q - 1) CRT param */
  publicKey.dQ = NULL;

  /* if no key is provided, we look in the index, to create a proper KEY structure. */
  if(rawKey == NULL )
  {
    error = Crypto_getKeybyIndex(&publicKey, keyIndex, PK_RSA);
    if ( error != CRYPTO_E_OK){
      return error;
    }
  }else
  {
    /* read the byte array of the raw key  and format it into a proper rsa key structure. */
    mp_read_unsigned_bin(publicKey.e, rawKey->pubKeyExponent, rawKey->length);
    mp_read_unsigned_bin(publicKey.N, rawKey->pubKeyModulus, rawKey->length);
  }
  /* Perform RSA verification. */
  /* Todo : replace return values type with Crypto_ReturnType for all RSA internal functions. */
  error = rsa_verify_hash_ex( signature, signatureLength, hash, hashLength, padding, hashingIndex, saltlen, result, &publicKey);
  return error;
}


#define Crypto_STOP_SEC_CODE
#include "Crypto_MemMap.h"
