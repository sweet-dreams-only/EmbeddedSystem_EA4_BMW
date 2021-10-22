/**
*  \file
*
*  \brief       BMW Crypto Library
*
*  This file contains a mathematical function for the BMW Crypto Library
*  It is based on the WTFPL library TomFastMath but has been changed for BMW purposes.
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
#include "Crypto.h"
#include "Crypto_Version.h"

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!Crypto_CHECK_VERSION(5,2,0))
#error "Version of mem_neq.c does not match the version of the module!"
#endif

/*------------------------------------------------------------------------------
                      Global Functions
------------------------------------------------------------------------------*/

#define Crypto_START_SEC_CODE
#include "Crypto_MemMap.h"

/**
   \brief
   Compare two blocks of memory for inequality in constant time.

   The usage is similar to that of standard memcmp, but you can only test
   if the memory is equal or not - you can not determine by how much the
   first different byte differs.

   This function shall be used to compare results of cryptographic
   operations where inequality means most likely usage of a wrong key.
   The execution time has therefore to be constant as otherwise
   timing attacks could be possible.

   \param a     The first memory region
   \param b     The second memory region
   \param len   The length of the area to compare (octets)

   \return 0 when a and b are equal for len bytes, 1 they are not equal.
*/
uint8 mem_neq(const void *a, const void *b, size_t len)
{
   uint8 ret = 0;
   const uint8 *pa;
   const uint8 *pb;


   pa = a;
   pb = b;

   while (len-- > 0) {
      ret |= *pa ^ *pb;
      ++pa;
      ++pb;
   }

   ret |= ret >> 4;
   ret |= ret >> 2;
   ret |= ret >> 1;
   ret &= 1;

   return ret;
}


#define Crypto_STOP_SEC_CODE
#include "Crypto_MemMap.h"