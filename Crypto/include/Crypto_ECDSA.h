/**
*  \file
*
*  \brief       BMW Crypto Library
*
*  This file is the extern definition header file of the generic part of the
*  Crypto lib for usage in the BMW AUTOSAR Core.
*  It is to be included by the two adapaters and by any software wishing to acess directly the library.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.2.0
*
*/


#ifndef CRYPTO_ECDSA_H
#define CRYPTO_ECDSA_H


/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "BUtil/PlatformTypes.h"
#include "Crypto_Common.h"
#include "Crypto_KeyManagement.h"
#include <stddef.h>
#include "Crypto_Version.h"

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!Crypto_CHECK_VERSION(5,2,0))
#error "Version of Crypto_ECDSA.h does not match the version of the module!"
#endif



#ifdef __cplusplus
extern  "C" {
#endif


/*------------------------------------------------------------------------------
                      Data Types
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Global Variables
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Global Constants
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Global Function Declarations
------------------------------------------------------------------------------*/

/* ECDSA */
Crypto_ReturnType Crypto_EccVerifyHash(const uint8*                    signature,
                                       size_t                          signatureLength,
                                       const uint8*                    hash,
                                       size_t                          hashLength,
                                       uint8                           keyIndex,
                                       eccPublicKeyStruct              *rawKey,
                                       sint8                           *result);




#ifdef __cplusplus
}
#endif

#endif /* CRYPTO_ECDSA_EXTERN_H */
