/**
*  \file
*
*  \brief       BMW Crypto Library
*
*  This file contains a mathematical function for the BMW Crypto Library
*  It is based on the WTFPL library TomFastMath but has been changed for BMW purposes.
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

#include "Crypto_Math_Intern.h"
#include "Crypto_Version.h"

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!Crypto_CHECK_VERSION(5,2,0))
#error "Version of fp_montgomery_calc_normalization.c does not match the version of the module!"
#endif

/*------------------------------------------------------------------------------
                      Global Functions
------------------------------------------------------------------------------*/

#define Crypto_START_SEC_CODE
#include "Crypto_MemMap.h"


/* computes a = B**n mod b without division or multiplication useful for
 * normalizing numbers in a Montgomery system.
 */
void fp_montgomery_calc_normalization(fp_int *a, fp_int *b)
{
  uint32     x, bits;

  /* how many bits of last digit does b use */
  bits = fp_count_bits (b) % DIGIT_BIT;
  if (!bits) bits = DIGIT_BIT;

  /* compute A = B^(n-1) * 2^(bits-1) */
  if (b->used > 1) {
     fp_2expt (a, (b->used - 1) * DIGIT_BIT + bits - 1);
  } else {
     fp_set(a, 1);
     bits = 1;
  }

  /* now compute C = A * B mod b */
  for (x = bits - 1; x < (uint32)DIGIT_BIT; x++) {
    fp_mul_2 (a, a);
    if (fp_cmp_mag (a, b) != FP_LT) {
      s_fp_sub (a, b, a);
    }
  }
}


#define Crypto_STOP_SEC_CODE
#include "Crypto_MemMap.h"