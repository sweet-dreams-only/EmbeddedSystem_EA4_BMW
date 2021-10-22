/**
*  \file
*
*  \brief       Crypto Version Information
*
*  This file is the generated version header file of the classic adapter
*  of the Crypto module for usage in the BMW AUTOSAR Core.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.2.0
*
*  \remarks     --
*
*/

/*------------------------------------------------------------------------------
*
*  THIS FILE WAS GENERATED. DO NOT MODIFY!
*
*  GENERATOR       : BMW PAGe 1.1.0
*
*  GENERATION TIME : 2018-07-30 19:57:39.303018
*
------------------------------------------------------------------------------*/

#ifndef CRYPTOCLASSIC_VERSION_H
#define CRYPTOCLASSIC_VERSION_H


/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "Crypto_Version.h"     /* generic version header file                */

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/**
 * \brief Crypto header major version
 */
#define CryptoClassic_MAJOR_VERSION        (5u)

/**
 * \brief Crypto header minor version
 */
#define CryptoClassic_MINOR_VERSION        (2u)

/**
 * \brief Crypto header patch version
 */
#define CryptoClassic_PATCH_VERSION        (0u)


/*
   MISRA-C:2004 Rule 19.7: this macro is only used in preprocessor directive, no function possible
*/
/* PRQA S 3453 5 */
/* Version check macro for adapter part */
#define CryptoClassic_CHECK_VERSION(major,minor,patch) \
 (((major) == CryptoClassic_MAJOR_VERSION) && \
  ((minor) == CryptoClassic_MINOR_VERSION) && \
  ((patch) == CryptoClassic_PATCH_VERSION))

/*
   MISRA-C:2004 Rule 19.7: this macro is only used in preprocessor directive, no function possible
*/
/* PRQA S 3453 4 */
/* Version check macro for generic part */
#define CryptoGeneric_CHECK_VERSION(major,minor) \
 (((major) == Crypto_MAJOR_VERSION) && \
  ((minor) == Crypto_MINOR_VERSION))


/* check version of generic part */
#if (!CryptoGeneric_CHECK_VERSION(5,2))
#error "Version of Crypto classic adapter is incompatible to the generic module version!"
#endif
#endif /* CRYPTOCLASSIC_VERSION_H */


