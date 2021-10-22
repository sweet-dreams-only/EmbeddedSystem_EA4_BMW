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
#error "Version of fp_2expt.c does not match the version of the module!"
#endif

/*------------------------------------------------------------------------------
                      Global Functions
------------------------------------------------------------------------------*/

#define Crypto_START_SEC_CODE
#include "Crypto_MemMap.h"
/* computes a = 2**b */
void fp_2expt(fp_int *a, sint32 b)
{
   sint32 z;

   /* zero a as per default */
   fp_zero (a);

   if (b < 0) {
      return;
   }

   z = b / DIGIT_BIT;
   if (z >= FP_SIZE) {
      return;
   }

  /* set the used count of where the bit will go */
  a->used = z + 1;

  /* put the single bit in its place */
  a->dp[z] = ((fp_digit)1) << (b % DIGIT_BIT);
}
#define Crypto_STOP_SEC_CODE
#include "Crypto_MemMap.h"