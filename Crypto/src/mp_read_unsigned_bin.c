/**
*  \file
*
*  \brief       BMW Crypto Library
*
*  This file contains the function for reading binary array and setting
*  them into the appropriate form to be processed by the other math functions.
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

#include "Crypto_Math_Intern.h"
#include "Crypto_Version.h"

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!Crypto_CHECK_VERSION(5,2,0))
#error "Version of mp_read_unsigned_bin.c does not match the version of the module!"
#endif

/*------------------------------------------------------------------------------
                      Global Functions
------------------------------------------------------------------------------*/

#define Crypto_START_SEC_CODE
#include "Crypto_MemMap.h"





/* reads a unsigned char array, assumes the msb is stored first [big endian] */
void mp_read_unsigned_bin (mp_int * a, const uint8 *b, uint32 c)
{

  /* zero the int */
  mp_zero (a);

  /* read the bytes in */
  while (c-- > 0u) {
    fp_mul_2d (a, 8, a);
    a->dp[0] |= *b++;
    a->used += 1;
  }
  fp_clamp (a);
  return;
}

/* reads an unsigned int 32 array assumes the msb is stored first. */
void mp_read_unsigned_bin_uint32 (mp_int * a, const uint32 *b, uint16 c)
{

  /* zero the int */
  mp_zero (a);

  /* read the bytes in */
  while (c-- > 0u) {
    fp_mul_2d (a, 32, a);

    a->dp[0] |= (*b++ );
    a->used += 1u;
    }
  mp_clamp (a);
  return;
}

/* reads an unsigned int 32 array assumes the msb is stored last.*/
void mp_read_unsigned_bin_uint32_LE (mp_int * a, const uint32 *b, uint16 c)
{
  /* zero the int */
  mp_zero (a);

  b = &b[c-1];
  /* read the bytes in */
  while (c-- > 0u) {
    fp_mul_2d (a, 32, a);

    a->dp[0] |= (*b--);
    a->used += 1u;
  }
  mp_clamp (a);
  return;
}


#define Crypto_STOP_SEC_CODE
#include "Crypto_MemMap.h"
