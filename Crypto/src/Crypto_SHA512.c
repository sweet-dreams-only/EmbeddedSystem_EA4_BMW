/**
*  \file
*
*  \brief       Crypto SHA 512 Functionnality
*
*  This file contains the function for the SHA512 hash function.
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


#include "Crypto_Common_Intern.h"
#include "Crypto_Hash.h"
#include "string.h"
#include "Crypto_BitOperations.h"
#include "BUtil_Algorithm.h"
#include "Crypto_Version.h"
#include "BUtil_ByteMask.h"


/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!Crypto_CHECK_VERSION(5,2,0))
#error "Version of Crypto_SHA512.c does not match the version of the module!"
#endif

#ifdef __cplusplus
extern  "C" {
#endif


/* Various logical functions */
#define Ch(x,y,z)       (z ^ (x & (y ^ z)))
#define Maj(x,y,z)      (((x | y) & z) | (x & y))
#define S(x, n)         ROR64c(x, n)
#define R(x, n)         (((x)&0xFFFFFFFFFFFFFFFFULL)>>((uint64)n))
#define Sigma0(x)       (S(x, 28) ^ S(x, 34) ^ S(x, 39))
#define Sigma1(x)       (S(x, 14) ^ S(x, 18) ^ S(x, 41))
#define Gamma0(x)       (S(x, 1) ^ S(x, 8) ^ R(x, 7))
#define Gamma1(x)       (S(x, 19) ^ S(x, 61) ^ R(x, 6))


#define BLOCK_SIZE_IN_BYTES 128

/*------------------------------------------------------------------------------
                      Local Variables
------------------------------------------------------------------------------*/

#define Crypto_START_SEC_CONST_64
#include "Crypto_MemMap.h"

/* the K array */
static const uint64 K[80] = {
  0x428a2f98d728ae22ULL, 0x7137449123ef65cdULL,
  0xb5c0fbcfec4d3b2fULL, 0xe9b5dba58189dbbcULL,
  0x3956c25bf348b538ULL, 0x59f111f1b605d019ULL,
  0x923f82a4af194f9bULL, 0xab1c5ed5da6d8118ULL,
  0xd807aa98a3030242ULL, 0x12835b0145706fbeULL,
  0x243185be4ee4b28cULL, 0x550c7dc3d5ffb4e2ULL,
  0x72be5d74f27b896fULL, 0x80deb1fe3b1696b1ULL,
  0x9bdc06a725c71235ULL, 0xc19bf174cf692694ULL,
  0xe49b69c19ef14ad2ULL, 0xefbe4786384f25e3ULL,
  0x0fc19dc68b8cd5b5ULL, 0x240ca1cc77ac9c65ULL,
  0x2de92c6f592b0275ULL, 0x4a7484aa6ea6e483ULL,
  0x5cb0a9dcbd41fbd4ULL, 0x76f988da831153b5ULL,
  0x983e5152ee66dfabULL, 0xa831c66d2db43210ULL,
  0xb00327c898fb213fULL, 0xbf597fc7beef0ee4ULL,
  0xc6e00bf33da88fc2ULL, 0xd5a79147930aa725ULL,
  0x06ca6351e003826fULL, 0x142929670a0e6e70ULL,
  0x27b70a8546d22ffcULL, 0x2e1b21385c26c926ULL,
  0x4d2c6dfc5ac42aedULL, 0x53380d139d95b3dfULL,
  0x650a73548baf63deULL, 0x766a0abb3c77b2a8ULL,
  0x81c2c92e47edaee6ULL, 0x92722c851482353bULL,
  0xa2bfe8a14cf10364ULL, 0xa81a664bbc423001ULL,
  0xc24b8b70d0f89791ULL, 0xc76c51a30654be30ULL,
  0xd192e819d6ef5218ULL, 0xd69906245565a910ULL,
  0xf40e35855771202aULL, 0x106aa07032bbd1b8ULL,
  0x19a4c116b8d2d0c8ULL, 0x1e376c085141ab53ULL,
  0x2748774cdf8eeb99ULL, 0x34b0bcb5e19b48a8ULL,
  0x391c0cb3c5c95a63ULL, 0x4ed8aa4ae3418acbULL,
  0x5b9cca4f7763e373ULL, 0x682e6ff3d6b2b8a3ULL,
  0x748f82ee5defb2fcULL, 0x78a5636f43172f60ULL,
  0x84c87814a1f0ab72ULL, 0x8cc702081a6439ecULL,
  0x90befffa23631e28ULL, 0xa4506cebde82bde9ULL,
  0xbef9a3f7b2c67915ULL, 0xc67178f2e372532bULL,
  0xca273eceea26619cULL, 0xd186b8c721c0c207ULL,
  0xeada7dd6cde0eb1eULL, 0xf57d4f7fee6ed178ULL,
  0x06f067aa72176fbaULL, 0x0a637dc5a2c898a6ULL,
  0x113f9804bef90daeULL, 0x1b710b35131c471bULL,
  0x28db77f523047d84ULL, 0x32caab7b40c72493ULL,
  0x3c9ebe0a15c9bebcULL, 0x431d67c49c100d4cULL,
  0x4cc5d4becb3e42b6ULL, 0x597f299cfc657e2aULL,
  0x5fcb6fab3ad6faecULL, 0x6c44198c4a475817ULL
};


#define Crypto_STOP_SEC_CONST_64
#include "Crypto_MemMap.h"


/*------------------------------------------------------------------------------
                       Local Functions
------------------------------------------------------------------------------*/


#define Crypto_START_SEC_CODE
#include "Crypto_MemMap.h"


/**
 * \brief  This function performs the hashing operation of 1024 bits and updates the hash state accordingly .
 *
 * \global_r  --
 * \global_w  --
 * \global_rw --
 *
 *
 * \param[out]  md        Pointer to a SHA Context, which has to be updated.
 * \param[out]  buf       Pointer to a byte array to process.
 *
 * \pre the pointers must be set (i.e. not null)
 *
 * \post the hash state is correctly updated.
 *
 *
 */
static void Crypto_SHA512Compress(hash_state * md, uint8 *buf)

{
  uint64 S[8], W[80], t0, t1;
  uint8 i;

  /* copy state into S */
  for (i = 0; i < 8; i++) {
    S[i] = md->sha512.state[i];
  }

  /* copy the state into 1024-bits into W[0..15] */
  for (i = 0; i < 16; i++) {
    W[i] = BUtil_Get64BitBigEndian (buf + (8*i));
  }

  /* fill W[16..79] */
  for (i = 16; i < 80; i++) {
    W[i] = Gamma1(W[i - 2]) + W[i - 7] + Gamma0(W[i - 15]) + W[i - 16];
  }

  /* Compress */
#define RND(a,b,c,d,e,f,g,h,i)                    \
     t0 = h + Sigma1(e) + Ch(e, f, g) + K[i] + W[i];   \
     t1 = Sigma0(a) + Maj(a, b, c);                  \
     d += t0;                                        \
     h  = t0 + t1;

  for (i = 0; i < 80; i += 8) {
    RND(S[0],S[1],S[2],S[3],S[4],S[5],S[6],S[7],i+0);
    RND(S[7],S[0],S[1],S[2],S[3],S[4],S[5],S[6],i+1);
    RND(S[6],S[7],S[0],S[1],S[2],S[3],S[4],S[5],i+2);
    RND(S[5],S[6],S[7],S[0],S[1],S[2],S[3],S[4],i+3);
    RND(S[4],S[5],S[6],S[7],S[0],S[1],S[2],S[3],i+4);
    RND(S[3],S[4],S[5],S[6],S[7],S[0],S[1],S[2],i+5);
    RND(S[2],S[3],S[4],S[5],S[6],S[7],S[0],S[1],i+6);
    RND(S[1],S[2],S[3],S[4],S[5],S[6],S[7],S[0],i+7);
  }


  /* feedback */
  for (i = 0; i < 8; i++) {
    md->sha512.state[i] = md->sha512.state[i] + S[i];
  }
}

/*------------------------------------------------------------------------------
                      Global Functions
------------------------------------------------------------------------------*/

/**
 * \brief  This function performs Initialization of the structure for the
 * SHA512 Hash process.
 *
 * \global_r  --
 * \global_w  --
 * \global_rw --
 *
 *
 * \param[out]  md        Pointer to a SHA Context, which has to be updated.
 *
 * \pre the pointer must be set (i.e. not null)
 *
 * \post the SHA context is correctly initialized.
 *
 * \reentrancy Reentrant
 *
 * \lhref CERT_603
 *
 */

void Crypto_SHA512Init(hash_state * md)
{
  md->sha512.curlen = 0;
  md->sha512.length = 0;
  md->sha512.state[0] = 0x6a09e667f3bcc908ULL;
  md->sha512.state[1] = 0xbb67ae8584caa73bULL;
  md->sha512.state[2] = 0x3c6ef372fe94f82bULL;
  md->sha512.state[3] = 0xa54ff53a5f1d36f1ULL;
  md->sha512.state[4] = 0x510e527fade682d1ULL;
  md->sha512.state[5] = 0x9b05688c2b3e6c1fULL;
  md->sha512.state[6] = 0x1f83d9abfb41bd6bULL;
  md->sha512.state[7] = 0x5be0cd19137e2179ULL;

}


/**
 * \brief  This function performs the main algorithm of the SHA512 Hash process.
 *
 * \global_r  --
 * \global_w  --
 * \global_rw --
 *
 *
 * \param[inout]  md        Pointer to a SHA Context, which has to be updated.
 * \param[in]     in        Pointer to the content to be hashed.
 * \param[in]     inlen     Size of the content to be hashed (in bytes)
 *
 *
 * \retval   CRYPTO_E_OK   Request successful
 * \retval   CRYPTO_E_NOK  Request failed ( null Pointer )
 *
 * \pre The pointer must be set (i.e. not null)
 *
 * \post The whole size of the input data has been processed and the hash state has been updated accordingly
 *       or CRYPTO_E_NOK is returned.
 *
 * \reentrancy Reentrant
 *
 * \lhref CERT_603
 *
 */
Crypto_ReturnType Crypto_SHA512Process(hash_state * md, const uint8 *in, uint32 inlen)
{
  uint32 n;

  /* correct argument check */
    if (md-> sha512 .curlen > sizeof(md-> sha512 .buf)) {
       return CRYPTO_E_NOK;
    }
    if ((md-> sha512 .length + inlen) < md-> sha512 .length) {
      return CRYPTO_E_NOK;
    }
    while (inlen > 0) {
        if (md-> sha512 .curlen == 0 && inlen >= BLOCK_SIZE_IN_BYTES) {
           Crypto_SHA512Compress (md, (uint8*)in);
           md-> sha512 .length += BLOCK_SIZE_IN_BYTES * 8;
           in             += BLOCK_SIZE_IN_BYTES;
           inlen          -= BLOCK_SIZE_IN_BYTES;
        } else {
           n = BUtil_MIN(inlen, (BLOCK_SIZE_IN_BYTES - md-> sha512 .curlen));
           memcpy(md-> sha512 .buf + md-> sha512.curlen, in, (size_t)n);
           md-> sha512 .curlen += n;
           in             += n;
           inlen          -= n;
           if (md-> sha512 .curlen == BLOCK_SIZE_IN_BYTES) {
              Crypto_SHA512Compress (md, md-> sha512 .buf);

              md-> sha512 .length += 8*BLOCK_SIZE_IN_BYTES;
              md-> sha512 .curlen = 0;
           }
       }
    }
    return CRYPTO_E_OK;
}


/**
 * \brief  This function performs the last part of the SHA512 Hash process.
 *
 * \global_r  --
 * \global_w  --
 * \global_rw --
 *
 *
 * \param[inout]  md        Pointer to a SHA Context, which has to be updated.
 * \param[inout]  out       Pointer to the hash result.
 * \returns  Error value.
 *
 * \retval   CRYPTO_E_OK   Request successful
 * \retval   CRYPTO_E_NOK  Request failed ( null Pointer )
 *
 * \pre The pointer must be set (i.e. not null)
 *
 * \post The pointer out contains the result of the hashing or CRYPTO_E_NOK is returned.
 *
 * \reentrancy Reentrant
 *
 * \lhref CERT_603
 *
 */

Crypto_ReturnType Crypto_SHA512Done(hash_state * md, uint8 *out)
{
  uint8 i;


  if (md->sha512.curlen >= sizeof(md->sha512.buf)) {
    return CRYPTO_E_NOK;
  }

  /* increase the length of the message */
  md->sha512.length += md->sha512.curlen * 8ULL;

  /* append the '1' bit */
  md->sha512.buf[md->sha512.curlen++] = (uint8)0x80;

  /* if the length is currently above 112 bytes we append zeros
   * then compress.  Then we can fall back to padding zeros and length
   * encoding like normal.
   */
  if (md->sha512.curlen > 112) {
    while (md->sha512.curlen < 128) {
      md->sha512.buf[md->sha512.curlen++] = (uint8)0;
    }
    Crypto_SHA512Compress(md, md->sha512.buf);
    md->sha512.curlen = 0;
  }

  /* pad upto 120 bytes of zeroes
   * note: that from 112 to 120 is the 64 MSB of the length.  We assume that you won't hash
   * > 2^64 bits of data... :-)
   */
  while (md->sha512.curlen < 120) {
    md->sha512.buf[md->sha512.curlen++] = (uint8)0;
  }

  /* store length */
  BUtil_Put64BitBigEndian((md->sha512.buf + 120), md->sha512.length);
  Crypto_SHA512Compress(md, md->sha512.buf);

  /* copy output */
  for (i = 0; i < 8; i++) {
    BUtil_Put64BitBigEndian(out+(8*i),md->sha512.state[i]);
  }
#ifdef LTC_CLEAN_STACK
  zeromem(md, sizeof(hash_state));
#endif
  return CRYPT_OK;
}

#define Crypto_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#ifdef __cplusplus
}
#endif