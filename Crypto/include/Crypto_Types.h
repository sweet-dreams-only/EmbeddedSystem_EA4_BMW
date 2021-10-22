/**
*  \file
*
*  \brief       BMW Crypto Library
*
*  This file is the type definition header file of the generic part of the
*  Crypto lib for usage in the BMW AUTOSAR Core.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.2.0
*
*/


#ifndef CRYPTO_TYPE_H
#define CRYPTO_TYPE_H

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "BUtil/PlatformTypes.h"
#include <stddef.h>
#include "Crypto_Version.h"


#ifdef __cplusplus
extern  "C" {
#endif

/*------------------------------------------------------------------------------
                              Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!Crypto_CHECK_VERSION(5,2,0))
#error "Version of Crypto_Types.h does not match the version of the module!"
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




#ifdef __cplusplus
}
#endif

#endif /* CRYPTO_TYPE_H */
