/**
*  \file
*
*  \brief       Crypto module template
*
*  This file is the Crypto c file containing all
*  standard ecc operations.
*  E.g : point addition, point doubling etc...
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
#include "Crypto_Version.h"

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!Crypto_CHECK_VERSION(5,2,0))
#error "Version of Crypto_EccOperations.c does not match the version of the module!"
#endif

/* size of our temp buffers for exported keys */
#define ECC_BUF_SIZE 256

/* max private key size */
#define ECC_MAXSIZE  66

#define Crypto_START_SEC_CODE
#include "Crypto_MemMap.h"

/*------------------------------------------------------------------------------
                      Local Functions
------------------------------------------------------------------------------*/
#ifdef __cplusplus
extern  "C" {
#endif


/*------------------------------------------------------------------------------
                      Global Functions
------------------------------------------------------------------------------*/


/**
* \brief  This function performs point addition as defined in NIST FIPS 186-3.
*
* \global_r  --
* \global_w  --
* \global_rw --
*
*
* \param[in]    P         The point to add.
* \param[in]    Q         The point to add.
* \param[out]   R         Result of the addition.
* \param[in]    modulus   The modulus of the field the ECC Curve is in.
* \param[in]    mp        Value from the montgomery setup.
*
* \retval      CRYPT_OK on success.
*
* \pre pointers are set and non null.
*
* \post --
*
* \reentrancy Reentrant
*
*/

sint8 ltc_ecc_projective_add_point(ecc_point *P, ecc_point *Q, ecc_point *R, void *modulus, mp_digit *mp)
{
  mp_int t1_data, t2_data, x_data, y_data, z_data;
  void  *t1, *t2, *x, *y, *z;
  sint8 err;

  /* set the pointers to have the same behaviour as in the libtom without dynamic allocation. */
  t1 = &t1_data;
  t2 = &t2_data;
  x  = &x_data;
  y  = &y_data;
  z  = &z_data;

  /* init the mp_int variables with 0 */
  Crypto_mpInit(t1);
  Crypto_mpInit(t2);
  Crypto_mpInit(x);
  Crypto_mpInit(y);
  Crypto_mpInit(z);

  /* should we dbl instead? */
  mp_sub(modulus, Q->y, t1);

  if ( (mp_cmp(P->x, Q->x) == LTC_MP_EQ) &&
       (Q->z != NULL && mp_cmp(P->z, Q->z) == LTC_MP_EQ) &&
       (mp_cmp(P->y, Q->y) == LTC_MP_EQ || mp_cmp(P->y, t1) == LTC_MP_EQ)) {

    return ltc_ecc_projective_dbl_point(P, R, modulus, mp);
  }

  mp_copy(P->x, x);
  mp_copy(P->y, y);
  mp_copy(P->z, z);

  /* if Z is one then these are no-operations */
  if (Q->z != NULL) {
    /* T1 = Z' * Z' */
    mp_sqr(Q->z, t1);
    if ((err = mp_montgomery_reduce(t1, modulus, *mp)) != CRYPTO_E_OK)            { goto done; }
    /* X = X * T1 */
    mp_mul(t1, x, x);
    if ((err = mp_montgomery_reduce(x, modulus, *mp)) != CRYPTO_E_OK)             { goto done; }
    /* T1 = Z' * T1 */
    mp_mul(Q->z, t1, t1);
    if ((err = mp_montgomery_reduce(t1, modulus, *mp)) != CRYPTO_E_OK)            { goto done; }
    /* Y = Y * T1 */
    mp_mul(t1, y, y);
    if ((err = mp_montgomery_reduce(y, modulus, *mp)) != CRYPTO_E_OK)             { goto done; }
  }

  /* T1 = Z*Z */
  mp_sqr(z, t1);
  if ((err = mp_montgomery_reduce(t1, modulus, *mp)) != CRYPTO_E_OK)              { goto done; }
  /* T2 = X' * T1 */
  mp_mul(Q->x, t1, t2);
  if ((err = mp_montgomery_reduce(t2, modulus, *mp)) != CRYPTO_E_OK)              { goto done; }
  /* T1 = Z * T1 */
  mp_mul(z, t1, t1);
  if ((err = mp_montgomery_reduce(t1, modulus, *mp)) != CRYPTO_E_OK)              { goto done; }
  /* T1 = Y' * T1 */
  mp_mul(Q->y, t1, t1);
  if ((err = mp_montgomery_reduce(t1, modulus, *mp)) != CRYPTO_E_OK)              { goto done; }

  /* Y = Y - T1 */
  mp_sub(y, t1, y);
  if (mp_cmp_d(y, 0) == LTC_MP_LT) {
    mp_add(y, modulus, y);
  }
  /* T1 = 2T1 */
  mp_add(t1, t1, t1);
  if (mp_cmp(t1, modulus) != LTC_MP_LT) {
    mp_sub(t1, modulus, t1);
  }
  /* T1 = Y + T1 */
  mp_add(t1, y, t1);
  if (mp_cmp(t1, modulus) != LTC_MP_LT) {
    mp_sub(t1, modulus, t1);
  }
  /* X = X - T2 */
  mp_sub(x, t2, x);
  if (mp_cmp_d(x, 0) == LTC_MP_LT) {
    mp_add(x, modulus, x);
  }
  /* T2 = 2T2 */
  mp_add(t2, t2, t2);
  if (mp_cmp(t2, modulus) != LTC_MP_LT) {
    mp_sub(t2, modulus, t2);
  }
  /* T2 = X + T2 */
  mp_add(t2, x, t2);
  if (mp_cmp(t2, modulus) != LTC_MP_LT) {
    mp_sub(t2, modulus, t2);
  }

  /* if Z' != 1 */
  if (Q->z != NULL) {
    /* Z = Z * Z' */
    mp_mul(z, Q->z, z);
    if ((err = mp_montgomery_reduce(z, modulus, *mp)) != CRYPTO_E_OK)            { goto done; }
  }

  /* Z = Z * X */
  mp_mul(z, x, z);
  if ((err = mp_montgomery_reduce(z, modulus, *mp)) != CRYPTO_E_OK)               { goto done; }

  /* T1 = T1 * X  */
  mp_mul(t1, x, t1);
  if ((err = mp_montgomery_reduce(t1, modulus, *mp)) != CRYPTO_E_OK)              { goto done; }
  /* X = X * X */
  mp_sqr(x, x);
  if ((err = mp_montgomery_reduce(x, modulus, *mp)) != CRYPTO_E_OK)               { goto done; }
  /* T2 = T2 * x */
  mp_mul(t2, x, t2);
  if ((err = mp_montgomery_reduce(t2, modulus, *mp)) != CRYPTO_E_OK)              { goto done; }
  /* T1 = T1 * X  */
  mp_mul(t1, x, t1);
  if ((err = mp_montgomery_reduce(t1, modulus, *mp)) != CRYPTO_E_OK)              { goto done; }

  /* X = Y*Y */
  mp_sqr(y, x);
  if ((err = mp_montgomery_reduce(x, modulus, *mp)) != CRYPTO_E_OK)               { goto done; }
  /* X = X - T2 */
  mp_sub(x, t2, x);
  if (mp_cmp_d(x, 0) == LTC_MP_LT) {
    mp_add(x, modulus, x);
  }

  /* T2 = T2 - X */
  mp_sub(t2, x, t2);
  if (mp_cmp_d(t2, 0) == LTC_MP_LT) {
    mp_add(t2, modulus, t2);
  }
  /* T2 = T2 - X */
  mp_sub(t2, x, t2);
  if (mp_cmp_d(t2, 0) == LTC_MP_LT) {
    mp_add(t2, modulus, t2);
  }
  /* T2 = T2 * Y */
  mp_mul(t2, y, t2);
  if ((err = mp_montgomery_reduce(t2, modulus, *mp)) != CRYPTO_E_OK)              { goto done; }
  /* Y = T2 - T1 */
  mp_sub(t2, t1, y);
  if (mp_cmp_d(y, 0) == LTC_MP_LT) {
    mp_add(y, modulus, y);
  }
  /* Y = Y/2 */
  if (mp_isodd((mp_int*)y)) {
    mp_add(y, modulus, y);
  }
  mp_div_2(y, y);

  mp_copy(x, R->x);
  mp_copy(y, R->y);
  mp_copy(z, R->z);

  err = CRYPTO_E_OK;
  done:
  return err;
}

/**
 * \brief  This function maps a projective jacobian point back to affine space.
 *
 * \global_r  --
 * \global_w  --
 * \global_rw --
 *
 *
 * \param[inout] P         The point to map.
 * \param[in]    modulus   The modulus of the field the ECC Curve is in.
 * \param[in]    mp        B value from the montgomery setup.
 *
 * \retval      CRYPT_OK on success.
 *
 * \pre pointers are set and non null.
 *
 * \post --
 *
 * \reentrancy Reentrant
 *
 */

sint8 ltc_ecc_map(ecc_point *P, void *modulus, mp_digit *mp)
{
  void *t1, *t2;
  sint8 err;

  mp_int t1_data, t2_data;

  t1 = &t1_data;
  t2 = &t2_data;

  Crypto_mpInit(t1);
  Crypto_mpInit(t2);

  /* first map z back to normal */
  if ((err = mp_montgomery_reduce(P->z, modulus, *mp)) != CRYPT_OK)           { goto done; }

  /* get 1/z */
  if ((err = mp_invmod(P->z, modulus, t1)) != CRYPT_OK)                      { goto done; }

  /* get 1/z^2 and 1/z^3 */
  mp_sqr(t1, t2);
  if ((err = mp_mod(t2, modulus, t2)) != CRYPT_OK)                           { goto done; }
  mp_mul(t1, t2, t1);
  if ((err = mp_mod(t1, modulus, t1)) != CRYPT_OK)                           { goto done; }

  /* multiply against x/y */
  mp_mul(P->x, t2, P->x);
  if ((err = mp_montgomery_reduce(P->x, modulus, *mp)) != CRYPT_OK)           { goto done; }
  mp_mul(P->y, t1, P->y);
  if ((err = mp_montgomery_reduce(P->y, modulus, *mp)) != CRYPT_OK)           { goto done; }
  mp_set(P->z, 1) ;

  err = CRYPT_OK;
  done:

  return err;
}



/**
* \brief  This function performs point multiplication as defined in NIST FIPS 186-3. .
*
* \global_r  --
* \global_w  --
* \global_rw --
*
*
* \param[in]    k         scalar to multipliy by (integer).
* \param[in]    Q         The point to multiply.
* \param[out]   R         Result of the multiplication.
* \param[in]    modulus   The modulus of the field the ECC Curve is in.
* \param[in]    map       boolean defining if we should map the resulting point back to affine space.
*
* \retval      CRYPT_OK on success.
*
* \pre pointers are set and non null.
*
* \post --
*
* \reentrancy Reentrant
*
*/

sint8 ltc_ecc_mulmod(mp_int *k, ecc_point *G, ecc_point *R, void *modulus, sint32 map)
{
  ecc_point *tG, *M[3];
  sint32    i;
  sint8     err;
  void      *mu;
  mp_digit  mp;
  uint32    buf;
  sint32    bitcnt, mode, digidx;

  mp_int   mu_data;
  mp_int   tG_data_x, tG_data_y, tG_data_z, M_data_x[3], M_data_y[3], M_data_z[3];
  ecc_point tG_data, M_data[3];

  mu = &mu_data;
  Crypto_mpInit(mu);

  /* Init of the points tG and M[] with local variables. */
  /* ( needed because we do not use dynamic allocation ) */

  tG   = &tG_data;
  tG_data.x = &tG_data_x;
  tG_data.y = &tG_data_y;
  tG_data.z = &tG_data_z;
  Crypto_mpInit(tG_data.x);
  Crypto_mpInit(tG_data.y);
  Crypto_mpInit(tG_data.z);


  for (i = 0; i < 3 ; ++i) {
    M[i] = &M_data[i];
    M_data[i].x = &M_data_x[i];
    M_data[i].y = &M_data_y[i];
    M_data[i].z = &M_data_z[i];
    Crypto_mpInit(M_data[i].x);
    Crypto_mpInit(M_data[i].y);
    Crypto_mpInit(M_data[i].z);
  }

  /* init montgomery reduction */
  if ((err = mp_montgomery_setup(modulus, &mp)) != CRYPT_OK) {
    return err;
  }

  mp_montgomery_calc_normalization(mu, modulus);

  /* make a copy of G incase R==G */
  /* tG = G  and convert to montgomery */
  if ((err = mp_mulmod(G->x, mu, modulus, tG->x)) != CRYPT_OK)                      { goto done; }
  if ((err = mp_mulmod(G->y, mu, modulus, tG->y)) != CRYPT_OK)                      { goto done; }
  if ((err = mp_mulmod(G->z, mu, modulus, tG->z)) != CRYPT_OK)                      { goto done; }

  /* calc the M tab */
  /* M[0] == G */
  mp_copy(tG->x, M[0]->x);
  mp_copy(tG->y, M[0]->y);
  mp_copy(tG->z, M[0]->z);
  /* M[1] == 2G */
  if ((err = ltc_ecc_projective_dbl_point(tG, M[1], modulus, &mp)) != CRYPT_OK)                  { goto done; }

  /* setup sliding window */
  mode   = 0;
  bitcnt = 1;
  buf    = 0;
  digidx = k->used - 1;

  /* perform ops */
  for (;;) {
    /* grab next digit as required */
    if (--bitcnt == 0) {
      if (digidx == -1) {
        break;
      }
      buf    = mp_get_digit(k, digidx);
      bitcnt = (sint32) MP_DIGIT_BIT;
      --digidx;
    }

    /* grab the next msb from the ltiplicand */
    i = (buf >> (MP_DIGIT_BIT - 1)) & 1;
    buf <<= 1;

    if (mode == 0 && i == 0) {
      /* dummy operations */
      if ((err = ltc_ecc_projective_add_point(M[0], M[1], M[2], modulus, &mp)) != CRYPT_OK)    { goto done; }
      if ((err = ltc_ecc_projective_dbl_point(M[1], M[2], modulus, &mp)) != CRYPT_OK)          { goto done; }
      continue;
    }

    if (mode == 0 && i == 1) {
      mode = 1;
      /* dummy operations */
      if ((err = ltc_ecc_projective_add_point(M[0], M[1], M[2], modulus, &mp)) != CRYPT_OK)    { goto done; }
      if ((err = ltc_ecc_projective_dbl_point(M[1], M[2], modulus, &mp)) != CRYPT_OK)          { goto done; }
      continue;
    }

    if ((err = ltc_ecc_projective_add_point(M[0], M[1], M[i^1], modulus, &mp)) != CRYPT_OK)     { goto done; }
    if ((err = ltc_ecc_projective_dbl_point(M[i], M[i], modulus, &mp)) != CRYPT_OK)             { goto done; }
  }

  /* copy result out */
  mp_copy(M[0]->x, R->x);
  mp_copy(M[0]->y, R->y);
  mp_copy(M[0]->z, R->z);

  /* map R back from projective space */
  if (map) {
    err = ltc_ecc_map(R, modulus, &mp);
  } else {
    err = CRYPT_OK;
  }
  done:
  return err;
}




/**
 * \brief  This function performs point doubling as defined in NIST FIPS 186-3. .
 *
 * \global_r  --
 * \global_w  --
 * \global_rw --
 *
 *
 * \param[in]    P         The point to double.
 * \param[out]   R         Result of the operation.
 * \param[in]    modulus   The modulus of the field the ECC Curve is in.
 * \param[in]    mp        B value from the montgomery setup.
 *
 * \retval      CRYPT_OK on success.
 *
 * \pre pointers are set and non null.
 *
 * \post --
 *
 * \reentrancy Reentrant
 *
 */
sint8 ltc_ecc_projective_dbl_point(ecc_point *P, ecc_point *R, void *modulus, mp_digit *mp)
{
  void *t1, *t2;
  sint8 err;

  mp_int t1_data, t2_data;

  t1 = &t1_data;
  t2 = &t2_data;
  Crypto_mpInit(t1);
  Crypto_mpInit(t2);

  if (P != R) {
    mp_copy(P->x, R->x);
    mp_copy(P->y, R->y);
    mp_copy(P->z, R->z);
  }

  /* t1 = Z * Z */
  mp_sqr(R->z, t1);
  if ((err = mp_montgomery_reduce(t1, modulus, *mp)) != CRYPT_OK)                 { goto done; }
  /* Z = Y * Z */
  mp_mul(R->z, R->y, R->z);
  if ((err = mp_montgomery_reduce(R->z, modulus, *mp)) != CRYPT_OK)               { goto done; }
  /* Z = 2Z */
  mp_add(R->z, R->z, R->z);
  if (mp_cmp(R->z, modulus) != LTC_MP_LT) {
    mp_sub(R->z, modulus, R->z);
  }

  /* T2 = X - T1 */
  mp_sub(R->x, t1, t2);
  if (mp_cmp_d(t2, 0) == LTC_MP_LT) {
    mp_add(t2, modulus, t2);
  }
  /* T1 = X + T1 */
  mp_add(t1, R->x, t1);
  if (mp_cmp(t1, modulus) != LTC_MP_LT) {
    mp_sub(t1, modulus, t1);
  }
  /* T2 = T1 * T2 */
  mp_mul(t1, t2, t2);
  if ((err = mp_montgomery_reduce(t2, modulus, *mp)) != CRYPT_OK)                 { goto done; }
  /* T1 = 2T2 */
  mp_add(t2, t2, t1);
  if (mp_cmp(t1, modulus) != LTC_MP_LT) {
    mp_sub(t1, modulus, t1);
  }
  /* T1 = T1 + T2 */
  mp_add(t1, t2, t1);
  if (mp_cmp(t1, modulus) != LTC_MP_LT) {
    mp_sub(t1, modulus, t1);
  }

  /* Y = 2Y */
  mp_add(R->y, R->y, R->y);
  if (mp_cmp(R->y, modulus) != LTC_MP_LT) {
    mp_sub(R->y, modulus, R->y);
  }
  /* Y = Y * Y */
  mp_sqr(R->y, R->y);
  if ((err = mp_montgomery_reduce(R->y, modulus, *mp)) != CRYPT_OK)               { goto done; }
  /* T2 = Y * Y */
  mp_sqr(R->y, t2);
  if ((err = mp_montgomery_reduce(t2, modulus, *mp)) != CRYPT_OK)                 { goto done; }
  /* T2 = T2/2 */
  if (mp_isodd((mp_int*)t2)) {
    mp_add(t2, modulus, t2);
  }
  mp_div_2(t2, t2);
  /* Y = Y * X */
  mp_mul(R->y, R->x, R->y);
  if ((err = mp_montgomery_reduce(R->y, modulus, *mp)) != CRYPT_OK)               { goto done; }

  /* X  = T1 * T1 */
  mp_sqr(t1, R->x);
  if ((err = mp_montgomery_reduce(R->x, modulus, *mp)) != CRYPT_OK)                { goto done; }
  /* X = X - Y */
  mp_sub(R->x, R->y, R->x);
  if (mp_cmp_d(R->x, 0) == LTC_MP_LT) {
    mp_add(R->x, modulus, R->x);
  }
  /* X = X - Y */
  mp_sub(R->x, R->y, R->x);
  if (mp_cmp_d(R->x, 0) == LTC_MP_LT) {
    mp_add(R->x, modulus, R->x);
  }

  /* Y = Y - X */
  mp_sub(R->y, R->x, R->y);
  if (mp_cmp_d(R->y, 0) == LTC_MP_LT) {
    mp_add(R->y, modulus, R->y);
  }
  /* Y = Y * T1 */
  mp_mul(R->y, t1, R->y);
  if ((err = mp_montgomery_reduce(R->y, modulus, *mp)) != CRYPT_OK)               { goto done; }
  /* Y = Y - T2 */
  mp_sub(R->y, t2, R->y);
  if (mp_cmp_d(R->y, 0) == LTC_MP_LT) {
    mp_add(R->y, modulus, R->y);
  }

  err = CRYPT_OK;
  done:

  return err;
}


/**
 * \brief  This function Computes kA*A + kB*B = C using Shamir's Trick.
 *
 * \global_r  --
 * \global_w  --
 * \global_rw --
 *
 *
*  \param[in] A        First point to multiply
*  \param[in] kA       What to multiple A by
*  \param[in] B        Second point to multiply
*  \param[in] kB       What to multiple B by
*  \param[out] C       Destination point (can overlap with A or B)
*  \param[in] modulus  Modulus for curve
 *
 * \retval      CRYPT_OK on success.
 *
 * \pre pointers are set and non null.
 *
 * \post --
 *
 * \reentrancy Reentrant
 *
 */

Crypto_ReturnType ltc_ecc_mul2add(ecc_point *A, void *kA,
                                  ecc_point *B, void *kB,
                                  ecc_point *C,
                                  void *modulus) {
  ecc_point *precomp[16];
  ecc_point precomp_data[16];
  mp_int precomp_data_x[16], precomp_data_y[16], precomp_data_z[16], mu_data;
  uint32 bitbufA, bitbufB, lenA, lenB, len, x, y, nA, nB, nibble;
  uint8 tA[ECC_BUF_SIZE], tB[ECC_BUF_SIZE];
  sint32 err, first;
  mp_int *mu;
  mp_digit mp;


  mu = &mu_data;

  /* get sizes */
  lenA = mp_unsigned_bin_size(kA);
  lenB = mp_unsigned_bin_size(kB);
  len = BUtil_MAX(lenA, lenB);

  /* sanity check */
  if ((lenA > ECC_BUF_SIZE) || (lenB > ECC_BUF_SIZE)) {
    err = CRYPTO_E_NOK;
    goto ERR_T;
  }

  /* extract and justify kA */
  mp_to_unsigned_bin(kA, (len - lenA) + tA);

  /* extract and justify kB */
  mp_to_unsigned_bin(kB, (len - lenB) + tB);

  /* allocate the table */
  for (x = 0u; x < 16u; x++) {
    precomp[x] = &precomp_data[x];
    precomp_data[x].x = &precomp_data_x[x];
    precomp_data[x].y = &precomp_data_y[x];
    precomp_data[x].z = &precomp_data_z[x];
    Crypto_mpInit(precomp_data[x].x);
    Crypto_mpInit(precomp_data[x].y);
    Crypto_mpInit(precomp_data[x].z);
  }

  /* init montgomery reduction */
  if ((err = mp_montgomery_setup(modulus, &mp)) != CRYPT_OK) {
    goto ERR_P;
  }
  Crypto_mpInit(mu);

  mp_montgomery_calc_normalization(mu, modulus);

  /* copy ones ... */
  if ((err = mp_mulmod(A->x, mu, modulus, precomp[1]->x)) != CRYPT_OK) { goto ERR_MU; }
  if ((err = mp_mulmod(A->y, mu, modulus, precomp[1]->y)) != CRYPT_OK) { goto ERR_MU; }
  if ((err = mp_mulmod(A->z, mu, modulus, precomp[1]->z)) != CRYPT_OK) { goto ERR_MU; }

  if ((err = mp_mulmod(B->x, mu, modulus, precomp[1 << 2]->x)) != CRYPT_OK) { goto ERR_MU; }
  if ((err = mp_mulmod(B->y, mu, modulus, precomp[1 << 2]->y)) != CRYPT_OK) { goto ERR_MU; }
  if ((err = mp_mulmod(B->z, mu, modulus, precomp[1 << 2]->z)) != CRYPT_OK) { goto ERR_MU; }

  /* precomp [i,0](A + B) table */
  if ((err = ltc_ecc_projective_dbl_point(precomp[1], precomp[2], modulus, &mp)) != CRYPT_OK) { goto ERR_MU; }
  if ((err = ltc_ecc_projective_add_point(precomp[1], precomp[2], precomp[3], modulus, &mp)) !=
      CRYPT_OK) { goto ERR_MU; }

  /* precomp [0,i](A + B) table */
  if ((err = ltc_ecc_projective_dbl_point(precomp[1 << 2], precomp[2 << 2], modulus, &mp)) != CRYPT_OK) { goto ERR_MU; }
  if ((err = ltc_ecc_projective_add_point(precomp[1 << 2], precomp[2 << 2], precomp[3 << 2], modulus, &mp)) !=
      CRYPT_OK) { goto ERR_MU; }

  /* precomp [i,j](A + B) table (i != 0, j != 0) */
  for (x = 1; x < 4; x++) {
    for (y = 1; y < 4; y++) {
      if ((err = ltc_ecc_projective_add_point(precomp[x], precomp[(y << 2)], precomp[x + (y << 2)], modulus, &mp)) !=
          CRYPT_OK) { goto ERR_MU; }
    }
  }

  nibble = 3;
  first = 1;
  bitbufA = tA[0];
  bitbufB = tB[0];

  /* for every byte of the multiplicands */
  for (x = -1;;) {
    /* grab a nibble */
    if (++nibble == 4) {
      ++x;
      if (x == len) break;
      bitbufA = tA[x];
      bitbufB = tB[x];
      nibble = 0;
    }

    /* extract two bits from both, shift/update */
    nA = (bitbufA >> 6) & 0x03;
    nB = (bitbufB >> 6) & 0x03;
    bitbufA = (bitbufA << 2) & 0xFF;
    bitbufB = (bitbufB << 2) & 0xFF;

    /* if both zero, if first, continue */
    if ((nA == 0) && (nB == 0) && (first == 1)) {
      continue;
    }

    /* double twice, only if this isn't the first */
    if (first == 0) {
      /* double twice */
      if ((err = ltc_ecc_projective_dbl_point(C, C, modulus, &mp)) != CRYPT_OK) { goto ERR_MU; }
      if ((err = ltc_ecc_projective_dbl_point(C, C, modulus, &mp)) != CRYPT_OK) { goto ERR_MU; }
    }

    /* if not both zero */
    if ((nA != 0) || (nB != 0)) {
      if (first == 1) {
        /* if first, copy from table */
        first = 0;
        mp_copy(precomp[nA + (nB << 2)]->x, C->x);
        mp_copy(precomp[nA + (nB << 2)]->y, C->y);
        mp_copy(precomp[nA + (nB << 2)]->z, C->z);
      } else {
        /* if not first, add from table */
        if ((err = ltc_ecc_projective_add_point(C, precomp[nA + (nB << 2)], C, modulus, &mp)) !=
            CRYPT_OK) { goto ERR_MU; }
      }
    }
  }

  /* reduce to affine */
  err = ltc_ecc_map(C, modulus, &mp);

  /* clean up */
  ERR_MU:

  ERR_P:

  ERR_T:
#ifdef LTC_CLEAN_STACK
  zeromem(tA, ECC_BUF_SIZE);
  zeromem(tB, ECC_BUF_SIZE);
#endif

  return err;
}



#define Crypto_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#ifdef __cplusplus
}
#endif