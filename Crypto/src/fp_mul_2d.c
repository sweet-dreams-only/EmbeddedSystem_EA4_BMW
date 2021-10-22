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
#error "Version of fp_mul_2d.c does not match the version of the module!"
#endif

/*------------------------------------------------------------------------------
                      Global Functions
------------------------------------------------------------------------------*/

#define Crypto_START_SEC_CODE
#include "Crypto_MemMap.h"


/* c = a * 2**d */
void fp_mul_2d(fp_int *a, sint32 b, fp_int *c)
{
   fp_digit carry, carrytmp, shift;
   sint32 x;

   /* copy it */
   fp_copy(a, c);

   /* handle whole digits */
   if (b >= DIGIT_BIT) {
      fp_lshd(c, b/DIGIT_BIT);
   }
   b %= DIGIT_BIT;

   /* shift the digits */
   if (b != 0) {
      carry = 0;
      shift = DIGIT_BIT - b;
      for (x = 0; x < (sint32) c->used; x++) {
          carrytmp = c->dp[x] >> shift;
          c->dp[x] = (c->dp[x] << b) + carry;
          carry = carrytmp;
      }
      /* store last carry if room */
      if (carry && x < FP_SIZE) {
         c->dp[c->used++] = carry;
      }
   }
   fp_clamp(c);
}


#define Crypto_STOP_SEC_CODE
#include "Crypto_MemMap.h"