/**
*  \file
*
*  \brief       Crypto module template
*
*  This file define the descriptor of the available hashes (for PKCS)
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
#include "Crypto_Version.h"

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!Crypto_CHECK_VERSION(5,2,0))
#error "Version of Crypto_HashDescriptor.c does not match the version of the module!"
#endif


/*------------------------------------------------------------------------------
                      Local Variables
------------------------------------------------------------------------------*/

#define Crypto_START_SEC_CONST_UNSPECIFIED
#include "Crypto_MemMap.h"

/* List of supported hash algorithms */
const hash_descriptor_t hash_descriptor[3] = {
  /* SHA256 parameters */
  {
    /* hash name */
    "sha256",
    /** internal ID */
    0u,
    /** Size of digest in octets */
    32u,
    /** Input block size in octets */
    64u,
    /* OID */
    { 2u, 16u, 840u, 1u, 101u, 3u, 4u, 2u, 1u,  },
    /* OID length */
    9u,
    /* Hash init function  */
    &Crypto_SHA256Init,
    /* Hash process function */
    &Crypto_SHA256Process,
    /* Hash done function */
    &Crypto_SHA256Done
  },
  /* SHA384 parameters */
  {
    /* hash name */
    "sha384",
    /** internal ID */
    1u,
    /** Size of digest in octets */
    48u,
    /** Input block size in octets */
    128u,
    /* OID */
    { 2u, 16u, 840u, 1u, 101u, 3u, 4u, 2u, 2u,  },
    /* OID length */
    9u,
    &Crypto_SHA384Init,
    &Crypto_SHA384Process,
    &Crypto_SHA384Done
  },
  /* SHA512 parameters */
  {
    /* hash name */
    "sha512",
    /** internal ID */
    2u,
    /** Size of digest in octets */
    64u,
    /** Input block size in octets */
    128u,
    /* OID */
    { 2u, 16u, 840u, 1u, 101u, 3u, 4u, 2u, 3u,  },
    /* OID length */
    9u,
    &Crypto_SHA512Init,
    &Crypto_SHA512Process,
    &Crypto_SHA512Done,
  }
};

#define Crypto_STOP_SEC_CONST_UNSPECIFIED
#include "Crypto_MemMap.h"

/*------------------------------------------------------------------------------
                      Global Functions
------------------------------------------------------------------------------*/


#define Crypto_START_SEC_CODE
#include "Crypto_MemMap.h"

sint8 hash_is_valid(uint8 idx)
{
  if ( idx >= (sizeof(hash_descriptor)/ sizeof(hash_descriptor[0])) || hash_descriptor[idx].name == NULL   ) {
    return CRYPTO_E_NOK;
  }
  return CRYPT_OK;
}

#define Crypto_STOP_SEC_CODE
#include "Crypto_MemMap.h"