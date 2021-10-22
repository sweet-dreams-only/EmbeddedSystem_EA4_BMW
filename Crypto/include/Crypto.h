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


#ifndef CRYPTO_H
#define CRYPTO_H

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "BUtil/PlatformTypes.h"
#include <stddef.h>

#include "Crypto_Common.h"
#include "Crypto_Hash.h"
#include "Crypto_KeyManagement.h"
#include "Crypto_ECDSA.h"
#include "Crypto_RSA.h"
#include "Crypto_Certificate.h"
#include "Crypto_Version.h"


/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!Crypto_CHECK_VERSION(5,2,0))
#error "Version of Crypto.h does not match the version of the module!"
#endif


#endif /* CRYPTO_H */
