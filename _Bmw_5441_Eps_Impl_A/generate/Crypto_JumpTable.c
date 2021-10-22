/**
*  \file
*
*  \brief       BMW Crypto Library
*
*  This file contains the jumptable used for direct access to the crypto routines. (e.g. : from the bootloader)
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

#include "Crypto_JumpTable.h"

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!CryptoClassic_CHECK_VERSION(5,2,0))
#error "Version of Crypto_JumpTable.c does not match the version of the module!"
#endif


#define  Crypto_START_SEC_CONST_JUMPTABLE
#include "Crypto_MemMap.h"


volatile const Crypto_JumpTableStruct CryptoJumptable = {
      &Crypto_SHA256Init,
  &Crypto_SHA256Process,
  &Crypto_SHA256Done,
          &Crypto_SHA384Init,
  &Crypto_SHA384Done,
          &Crypto_SHA512Init,
  &Crypto_SHA512Process,
  &Crypto_SHA512Done,
          &Crypto_EccVerifyHash,
          &Crypto_RsaVerifyHash,
          &Crypto_CertVerifiy,
    };

#define  Crypto_STOP_SEC_CONST_JUMPTABLE
#include "Crypto_MemMap.h"

