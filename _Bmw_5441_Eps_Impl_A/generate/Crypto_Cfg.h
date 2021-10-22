/*----------------------------------------------------------------------------*/
/**
*  \file
*
*  \brief       Crypto Configuration information
*
*  This file is a generated version header file
*  for usage in the BMW system function.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.2.0
*
*  \remarks     ---
*
*/
/*----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
*
*  THIS FILE WAS GENERATED. DO NOT MODIFY!
*
*  GENERATOR       : BMW PAGe 1.1.0
*
*  GENERATION TIME : 2018-07-30 19:57:39.370025
*
------------------------------------------------------------------------------*/

#ifndef CRYPTO_CFG_H
#define CRYPTO_CFG_H

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "Crypto_Version.h"

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!Crypto_CHECK_VERSION(5,2,0))
#error "Version of Crypto_Cfg.h does not match the version of the module!"
#endif



/* Shamir's trick. tradeoff RAM for Runtime */
/* Switch is off by default */

/* Shamir's Trick is deactivated, expect longer ECC verification time. */
#undef USING_SHAMIRS_TRICK


/* The following parameters create a significant increase in ROM size.
 * The goal is to have a tradeoff ROM for Runtime. */

/* These ones are always deactivated because they're not needed for the currently implemented functions. */
#if 0
#define TFM_MUL3
#define TFM_MUL4
#define TFM_MUL6
#define TFM_MUL7
#define TFM_MUL8
#define TFM_MUL9
#define TFM_MUL12
#define TFM_MUL17
#define TFM_MUL24
#define TFM_MUL28
#define TFM_MUL32
#define TFM_MUL48
#define TFM_MUL64
#define TFM_SQR3
#define TFM_SQR4
#define TFM_SQR6
#define TFM_SQR7
#define TFM_SQR8
#define TFM_SQR9
#define TFM_SQR12
#define TFM_SQR17
#define TFM_SQR24
#define TFM_SQR28
#define TFM_SQR32
#define TFM_SQR48
#define TFM_SQR64
#endif




#undef TFM_MUL20
#undef TFM_SQR20
#undef TFM_SMALL_SET


/* Maximal size needed for a digit. */
#define FP_MAX_SIZE           (384*2 + (8 * DIGIT_BIT))
#define MAX_SIGNATURE_LENGTH_IN_BYTES 48


/* RSA timing resistant functions are used */
#define TFM_TIMING_RESISTANT

/* Hardening and blinding are not necessary for now */
/* ToDo : make these security options configurable. */
#undef LTC_RSA_CRT_HARDENING
#undef LTC_RSA_BLINDING


#endif /* CRYPTO_CFG_H */

/*--- End of file ------------------------------------------------------------*/
