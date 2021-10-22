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


#ifndef CRYPTO_MATH_INTERN_H
#define CRYPTO_MATH_INTERN_H


/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include <stddef.h>
#include <string.h>
#include "BUtil/PlatformTypes.h"
#include "BUtil_Algorithm.h"
#include "Crypto_Types.h"
#include "Crypto_Common_Intern.h"
#include "Crypto_Version.h"
#include "Crypto_Cfg.h"

#ifdef __cplusplus
extern  "C" {
#endif


/*------------------------------------------------------------------------------
                              Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!Crypto_CHECK_VERSION(5,2,0))
#error "Version of Crypto_Math_Intern.h does not match the version of the module!"
#endif


/* Mapping LibtomCrypt functions to their TomFastMAth equivalent */
#define Crypto_mpInit(a)                        fp_init(a)
#define mp_copy(a,b)                            fp_copy(a,b)
#define mp_clamp(a)                             fp_clamp(a)
#define mp_zero(a)                              fp_zero(a)
#define mp_set(a,b)                             fp_set(a,b)
#define mp_cmp(a,b)                             fp_cmp(a,b)
#define mp_cmp_d(a,b)                           fp_cmp_d(a,b)
#define mp_cmp_mag(a,b)                         fp_cmp_mag(a,b)
#define mp_sub(a,b,c)                           fp_sub(a,b,c)
#define mp_add(a,b,c)                           fp_add(a,b,c)
#define mp_mul(a,b,c)                           fp_mul(a,b,c)
#define mp_sqr(a,b)                             fp_sqr(a,b)
#define mp_div_2(a,b)                           fp_div_2(a,b)
#define mp_mulmod(a,b,c,d)                      fp_mulmod(a,b,c,d)
#define mp_montgomery_reduce(a,b,c)             montgomery_reduce(a,b,c)
#define mp_mod(a,b,c)                           fp_mod(a,b,c)
#define mp_montgomery_calc_normalization(a,b)   fp_montgomery_calc_normalization(a,b)
#define mp_invmod(a,b,c)                        fp_invmod(a,b,c)
#define mp_to_unsigned_bin(a,b)                 fp_to_unsigned_bin(a,b)
#define mp_montgomery_setup(a,b)                fp_montgomery_setup(a,b)
#define mp_count_bits(a)                        fp_count_bits(a)
#define mp_unsigned_bin_size(a)                 fp_unsigned_bin_size(a)
#define mp_exptmod(a,b,c,d)                     fp_exptmod(a,b,c,d)


/* no processor specific code allowed */
#undef TFM_X86
#undef TFM_X86_64
#undef TFM_SSE2
#undef TFM_ARM
#undef TFM_PPC32
#undef TFM_PPC64
#undef TFM_AVR32
#undef TFM_ASM


/* using only standard ISO C */
#define TFM_ISO

/* standard ISO C lib calls are allowed */
#define USE_MEMSET

/* TODO : Make digit size and max size of an integer configurable to allow 64 bits configuration or  */
#define DIGIT_BIT   32


/* Max size of any number in bits.  Basically the largest size you will be multiplying
 * should be half [or smaller] of FP_MAX_SIZE-four_digit
 *
 * You can externally define this or it defaults to 4096-bits [allowing multiplications upto 2048x2048 bits ]
 */
#ifndef FP_MAX_SIZE
#define FP_MAX_SIZE           (4096*2 + (8 * DIGIT_BIT)) /* max number  */
#endif

#ifndef MAX_SIGNATURE_LENGTH_IN_BYTES
#define MAX_SIGNATURE_LENGTH_IN_BYTES 512
#endif

#define FP_SIZE    (FP_MAX_SIZE/DIGIT_BIT)
#define FP_MASK    (fp_digit)(-1)

#define fp_init(a)         (void)memset((a), 0, sizeof(fp_int))
#define fp_init_copy(a, b) fp_copy(b, a)
#define fp_copy(a, b)      (void)(((a) != (b)) && memcpy((b), (a), sizeof(fp_int)))
#define fp_zero(a)         fp_init(a)
/* clamp digits */
#define fp_clamp(a)   { while ((a)->used && (a)->dp[(a)->used-1] == 0) --((a)->used); (a)->sign = (a)->used ? (a)->sign : FP_ZPOS; }

/* zero/even/odd ? */
#define fp_iszero(a) (((a)->used == 0u) ? FP_YES : FP_NO)
#define fp_iseven(a) (((((a)->dp[0] & 1) == 0)) ? FP_YES : FP_NO)
#define fp_isodd(a)  (((a)->used > 0u  && (((a)->dp[0] & 1) == 1)) ? FP_YES : FP_NO)

/* negate and absolute */
#define fp_neg(a, b)  { fp_copy(a, b); (b)->sign ^= 1; fp_clamp(b); }
#define fp_abs(a, b)  { fp_copy(a, b); (b)->sign  = 0; }

/* remapping Math Library macros to BUTil Macros */
#ifndef MIN
#define MIN(x,y) BUtil_MIN(x,y)
#endif

#ifndef MAX
#define MAX(x,y) BUtil_MAX(x,y)
#endif






/*------------------------------------------------------------------------------
                      Global Constants
------------------------------------------------------------------------------*/

/* equalities */
#define FP_LT        -1   /* less than */
#define FP_EQ         0   /* equal to */
#define FP_GT         1   /* greater than */
/* sign */
#define FP_ZPOS       0   /* positive integer */
#define FP_NEG        1   /* negative */

/* Return values */
#define FP_OKAY       0   /* ok result */
#define FP_MEM        -2  /* out of mem */
#define FP_VAL        -3  /* invalid input */
#define FP_RANGE      MP_VAL

#define FP_YES        1   /* yes response */
#define FP_NO         0   /* no response */

#define MP_DIGIT_BIT        DIGIT_BIT

/*#define MP_MASK          ((((mp_digit)1)<<((mp_digit)DIGIT_BIT))-((mp_digit)1))*/


/* size of comba arrays, should be at least 2 * 2**(BITS_PER_WORD - BITS_PER_DIGIT*2) */
/*#define MP_WARRAY               (1 << (((sizeof(mp_word) * CHAR_BIT) - (2 * DIGIT_BIT)) + 1))*/

/* using standard digit size for a 32bits */
/*#define MP_DIGIT_BIT   28*/

/* ---> Basic Manipulations <--- */

#define mp_iszero(a) (((a)->used == 0) ? FP_YES : FP_NO)
#define mp_isodd(a)  ((((a)->used > 0) && (((a)->dp[0] & 1u) == 1u)) ? FP_YES : FP_NO)
#define mp_get_digit(a,n) (((mp_size)n >= a->used || n < 0) ? 0 : a->dp[n])
#define mp_get_digit_count(a) ((mp_int*)a)->used


/* activate bt */
/*#define BN_FAST_MP_INVMOD_C 1 */
/*#define BN_MP_INVMOD_SLOW_C 1 */

/* activate certain multiplication functions */
/*
#define BN_S_MP_MUL_DIGS_C
#define s_mp_mul(a, b, c) s_mp_mul_digs(a, b, c, (a)->used + (b)->used + 1)
*/

/* activate certain squaring functions */
/*#define BN_S_MP_SQR_C*/

/* init size and init are the same when working without dynamic allocation. */
/*#define mp_init_size(a,size) Crypto_mpInit(a) */


/*------------------------------------------------------------------------------
                      Data Types
------------------------------------------------------------------------------*/



typedef sint8              mp_sign;
typedef uint32             mp_size;

/* ToDo : add a configuration to have the possibility of using 64 bits datatype as digit */

/* Note :                                            */
/* - mp_digit needs to be at least DIGIT_BIT +1 bits */
/* - mp_word needs to be at least 2*DIGIT_BIT+1      */

/*typedef uint32             mp_digit; */ /* 4 byte type */
/*typedef uint64             mp_word;   *//* 8 byte type */


/* Defining the multiple precision integer datatype.  */
/* This is the standard datatype used by the math lib.*/

typedef uint32 fp_digit;
typedef uint64 fp_word;

typedef struct {
  fp_digit      dp[FP_SIZE];      /* the digits themselves      */
  mp_size       used;             /* how many digits used       */
  mp_sign       sign;             /* sign of this quantity      */
} fp_int;

typedef fp_int   mp_int;
typedef fp_digit mp_digit;

/*------------------------------------------------------------------------------
                      Global Variables
------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------
                      Global Function Declarations
------------------------------------------------------------------------------*/


void mp_read_unsigned_bin (mp_int * a, const uint8 *b, uint32 c);

void mp_read_unsigned_bin_uint32 (mp_int * a, const uint32 *b, uint16 c);

void mp_read_unsigned_bin_uint32_LE (mp_int * a, const uint32 *b, uint16 c);

void fp_set(fp_int *a, fp_digit b);

void fp_mul(fp_int *A, fp_int *B, fp_int *C);

sint8 fp_cmp(fp_int *a, fp_int *b);
sint8 fp_cmp_d(fp_int *a, fp_digit b);
sint8 fp_cmp_mag(fp_int *a, fp_int *b);
void s_fp_add(fp_int *a, fp_int *b, fp_int *c);
void fp_sub(fp_int *a, fp_int *b, fp_int *c);
void s_fp_sub(fp_int *a, fp_int *b, fp_int *c);
void fp_add(fp_int *a, fp_int *b, fp_int *c);
sint8 fp_mulmod(fp_int *a, fp_int *b, fp_int *c, fp_int *d);

Crypto_ReturnType montgomery_reduce(fp_int *a, fp_int *m, fp_digit mp);
void fp_montgomery_reduce(fp_int *a, fp_int *m, fp_digit mp);
void fp_montgomery_calc_normalization(fp_int *a, fp_int *b);
void fp_div_2(fp_int * a, fp_int * b);
sint8 fp_mod(fp_int *a, fp_int *b, fp_int *c);
uint32 fp_count_bits (fp_int * a);
void fp_rshd(fp_int *a, sint32 x);
void fp_mul_d(fp_int *a, fp_digit b, fp_int *c);
sint8 fp_div(fp_int *a, fp_int *b, fp_int *c, fp_int *d);
sint8 fp_invmod(fp_int *a, fp_int *b, fp_int *c);
void fp_to_unsigned_bin(fp_int *a, uint8 *b);
void fp_sqr(fp_int *a, fp_int *b);
void fp_mul_2(fp_int * a, fp_int * b);
void fp_mul_2d(fp_int *a, sint32 b, fp_int *c);
void fp_lshd(fp_int *a, sint32 x);
void fp_div_2d(fp_int *a, sint32 b, fp_int *c, fp_int *d);
void fp_mod_2d(fp_int *a, sint32 b, fp_int *c);
void fp_2expt(fp_int *a, sint32 b);
void fp_reverse (uint8 *s, sint32 len);
sint8 fp_montgomery_setup(fp_int *a, fp_digit *rho);
uint32 fp_unsigned_bin_size(fp_int *a);
sint8 fp_exptmod(fp_int * G, fp_int * X, fp_int * P, fp_int * Y);
void fp_mul_comba(fp_int *A, fp_int *B, fp_int *C);

#ifdef TFM_SMALL_SET
void fp_mul_comba_small(fp_int *A, fp_int *B, fp_int *C);
#endif

#ifdef TFM_MUL3
void fp_mul_comba3(fp_int *A, fp_int *B, fp_int *C);
#endif
#ifdef TFM_MUL4
void fp_mul_comba4(fp_int *A, fp_int *B, fp_int *C);
#endif
#ifdef TFM_MUL6
void fp_mul_comba6(fp_int *A, fp_int *B, fp_int *C);
#endif
#ifdef TFM_MUL7
void fp_mul_comba7(fp_int *A, fp_int *B, fp_int *C);
#endif
#ifdef TFM_MUL8
void fp_mul_comba8(fp_int *A, fp_int *B, fp_int *C);
#endif
#ifdef TFM_MUL9
void fp_mul_comba9(fp_int *A, fp_int *B, fp_int *C);
#endif
#ifdef TFM_MUL12
void fp_mul_comba12(fp_int *A, fp_int *B, fp_int *C);
#endif
#ifdef TFM_MUL17
void fp_mul_comba17(fp_int *A, fp_int *B, fp_int *C);
#endif

#ifdef TFM_MUL20
void fp_mul_comba20(fp_int *A, fp_int *B, fp_int *C);
#endif
#ifdef TFM_MUL24
void fp_mul_comba24(fp_int *A, fp_int *B, fp_int *C);
#endif
#ifdef TFM_MUL28
void fp_mul_comba28(fp_int *A, fp_int *B, fp_int *C);
#endif
#ifdef TFM_MUL32
void fp_mul_comba32(fp_int *A, fp_int *B, fp_int *C);
#endif
#ifdef TFM_MUL48
void fp_mul_comba48(fp_int *A, fp_int *B, fp_int *C);
#endif
#ifdef TFM_MUL64
void fp_mul_comba64(fp_int *A, fp_int *B, fp_int *C);
#endif



void fp_sqr_comba(fp_int *A, fp_int *B);

#ifdef TFM_SMALL_SET
void fp_sqr_comba_small(fp_int *A, fp_int *B);
#endif

#ifdef TFM_SQR3
void fp_sqr_comba3(fp_int *A, fp_int *B);
#endif
#ifdef TFM_SQR4
void fp_sqr_comba4(fp_int *A, fp_int *B);
#endif
#ifdef TFM_SQR6
void fp_sqr_comba6(fp_int *A, fp_int *B);
#endif
#ifdef TFM_SQR7
void fp_sqr_comba7(fp_int *A, fp_int *B);
#endif
#ifdef TFM_SQR8
void fp_sqr_comba8(fp_int *A, fp_int *B);
#endif
#ifdef TFM_SQR9
void fp_sqr_comba9(fp_int *A, fp_int *B);
#endif
#ifdef TFM_SQR12
void fp_sqr_comba12(fp_int *A, fp_int *B);
#endif
#ifdef TFM_SQR17
void fp_sqr_comba17(fp_int *A, fp_int *B);
#endif

#ifdef TFM_SQR20
void fp_sqr_comba20(fp_int *A, fp_int *B);
#endif
#ifdef TFM_SQR24
void fp_sqr_comba24(fp_int *A, fp_int *B);
#endif
#ifdef TFM_SQR28
void fp_sqr_comba28(fp_int *A, fp_int *B);
#endif
#ifdef TFM_SQR32
void fp_sqr_comba32(fp_int *A, fp_int *B);
#endif
#ifdef TFM_SQR48
void fp_sqr_comba48(fp_int *A, fp_int *B);
#endif
#ifdef TFM_SQR64
void fp_sqr_comba64(fp_int *A, fp_int *B);
#endif





#ifdef __cplusplus
}
#endif



#endif /* CRYPTO_MATH_INTERN_H */
