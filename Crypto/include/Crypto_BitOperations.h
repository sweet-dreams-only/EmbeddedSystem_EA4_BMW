/**
*  \file
*
*  \brief       BMW Crypto Library
*
*  This file is the header file of the bit operation macros use by the Crypto
*  lib for usage in the BMW AUTOSAR Core.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.2.0
*
*/

#ifndef CRYPTO_BIT_OPERATIONS_H
#define CRYPTO_BIT_OPERATIONS_H

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "Crypto_Version.h"

/*------------------------------------------------------------------------------
                      Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!Crypto_CHECK_VERSION(5,2,0))
#error "Version of Crypto_BitOperations.h does not match the version of the module!"
#endif

/* rotates the hard way (32 bits) */
#define ROL(x, y) ( (((uint32)(x)<<(uint32)((y)&31)) | (((uint32)(x)&0xFFFFFFFFUL)>>(uint32)(32-((y)&31)))) & 0xFFFFFFFFUL)
#define ROR(x, y) ( ((((uint32)(x)&0xFFFFFFFFUL)>>(uint32)((y)&31)) | ((uint32)(x)<<(uint32)(32-((y)&31)))) & 0xFFFFFFFFUL)
#define ROLc(x, y) ( (((uint32)(x)<<(uint32)((y)&31)) | (((uint32)(x)&0xFFFFFFFFUL)>>(uint32)(32-((y)&31)))) & 0xFFFFFFFFUL)
#define RORc(x, y) ( ((((uint32)(x)&0xFFFFFFFFUL)>>(uint32)((y)&31)) | ((uint32)(x)<<(uint32)(32-((y)&31)))) & 0xFFFFFFFFUL)

/* Rotation right (64 bits) */
#define ROR64c(x, y) \
    ( ((((x)&0xFFFFFFFFFFFFFFFFULL)>>((uint64)(y)&63ULL)) | \
      ((x)<<((uint64)(64-((y)&63ULL))))) & 0xFFFFFFFFFFFFFFFFULL)

#endif /* CRYPTO_BIT_OPERATIONS_H */
