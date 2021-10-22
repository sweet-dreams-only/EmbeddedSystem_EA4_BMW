/**
*  \file
*
*  \brief       Crypto SHA 384 functionnality
*
*  This file contains the function for the SHA384 hash function.
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
#include "Crypto_Version.h"


/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!Crypto_CHECK_VERSION(5,2,0))
#error "Version of Crypto_SHA384.c does not match the version of the module!"
#endif

#ifdef __cplusplus
extern  "C" {
#endif

/*------------------------------------------------------------------------------
                      Global Functions
------------------------------------------------------------------------------*/


#define Crypto_START_SEC_CODE
#include "Crypto_MemMap.h"

/**
 * \brief  This function performs Initialization of the structure for the
 * SHA384 Hash process.
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


void Crypto_SHA384Init(hash_state * md)
{


  md->sha512.curlen = 0;
  md->sha512.length = 0;
  md->sha512.state[0] = 0xcbbb9d5dc1059ed8ULL;
  md->sha512.state[1] = 0x629a292a367cd507ULL;
  md->sha512.state[2] = 0x9159015a3070dd17ULL;
  md->sha512.state[3] = 0x152fecd8f70e5939ULL;
  md->sha512.state[4] = 0x67332667ffc00b31ULL;
  md->sha512.state[5] = 0x8eb44a8768581511ULL;
  md->sha512.state[6] = 0xdb0c2e0d64f98fa7ULL;
  md->sha512.state[7] = 0x47b5481dbefa4fa4ULL;
  return ;
}


/**
 * \brief  This function performs the last part of the SHA384 Hash process.
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

Crypto_ReturnType Crypto_SHA384Done(hash_state * md, uint8 *out)
{
uint8 buf[64];

if (md->sha512.curlen >= sizeof(md->sha512.buf)) {
  return CRYPTO_E_NOK;
}

Crypto_SHA512Done(md, buf);
memcpy(out, buf, 48);
return CRYPT_OK;
}

#define Crypto_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#ifdef __cplusplus
}
#endif
