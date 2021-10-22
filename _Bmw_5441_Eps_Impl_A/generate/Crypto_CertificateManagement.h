/**
*  \file
*
*  \brief       BMW Crypto Library
*
*  This file is the definition of the Certificate management for the BMW Crypto library.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.2.0
*
*/

#ifndef CRYPTO_CERTIFICATEMANAGEMENT_H
#define CRYPTO_CERTIFICATEMANAGEMENT_H


/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "Crypto.h"
#include "CryptoClassic_Version.h"

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!CryptoClassic_CHECK_VERSION(5,2,0))
#error "Version of Crypto_CertificateManagement.h does not match the version of the module!"
#endif

/*------------------------------------------------------------------------------
                      Global Function Declarations
------------------------------------------------------------------------------*/
#define Crypto_START_SEC_CODE
#include "Crypto_MemMap.h"


extern Crypto_ReturnType Crypto_CertVerifiy( const uint8 *cert,
                                      eccPublicKeyStruct *rawKey,
                                      sint8* result);


#define Crypto_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#endif /* CRYPTO_CERTIFICATEMANAGEMENT_H */