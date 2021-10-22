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
#error "Version of fp_rshd.c does not match the version of the module!"
#endif

/*------------------------------------------------------------------------------
                      Global Functions
------------------------------------------------------------------------------*/

#define Crypto_START_SEC_CODE
#include "Crypto_MemMap.h"


void fp_rshd(fp_int *a, sint32 x)
{
  sint32 y;

  /* too many digits just zero and return */
  if (x >= (sint32) a->used) {
     fp_zero(a);
     return;
  }

   /* shift */
   for (y = 0; y < (sint32) a->used - x; y++) {
      a->dp[y] = a->dp[y+x];
   }

   /* zero rest */
   for (; y < (sint32) a->used; y++) {
      a->dp[y] = 0;
   }

   /* decrement count */
   a->used -= x;
   fp_clamp(a);
}


#define Crypto_STOP_SEC_CODE
#include "Crypto_MemMap.h"