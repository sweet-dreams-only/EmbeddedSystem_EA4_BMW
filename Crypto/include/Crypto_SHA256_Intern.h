/**
*  \file
*
*  \brief       BMW Crypto Library
*
*  This file is the  header file for the sha256 hash function of the generic
*  part of the Crypto lib for usage in the BMW AUTOSAR Core.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.2.0
*
*/


#ifndef CRYPTO_SHA256_H
#define CRYPTO_SHA256_H

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include <stddef.h>
#include "BUtil/PlatformTypes.h"
#include "Crypto_Common_Intern.h"
#include "Crypto_Version.h"



#ifdef __cplusplus
extern  "C" {
#endif

/*------------------------------------------------------------------------------
                              Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!Crypto_CHECK_VERSION(5,2,0))
#error "Version of Crypto_SHA256_Intern.h does not match the version of the module!"
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

#define Crypto_START_SEC_CODE
#include "Crypto_MemMap.h"



#define Crypto_STOP_SEC_CODE
#include "Crypto_MemMap.h"



#ifdef __cplusplus
}
#endif



#endif /* CRYPTO_SHA256_H */
