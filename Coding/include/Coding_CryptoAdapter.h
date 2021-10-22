/**
 * \file
 *
 * \brief       Coding Crypto Adapter
 *
 * \project     BMW Platform Software
 *
 * \copyright   BMW AG 2016 - 2017
 *
 * \version     5.2.1
 *
 */

#ifndef CODING_CRYPTOADAPTER_H_
#define CODING_CRYPTOADAPTER_H_

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/

#include <stddef.h>                  /* size_t */
#include "BUtil/PlatformTypes.h"     /* BMW Platform Types          */
#include "Coding.h"


/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/**
 * \brief check version of the module
 */
#if (!Coding_CHECK_VERSION(5, 2, 1))
#error "Version of Coding_CryptoAdapter.h does not match the version of the module!"
#endif


/*------------------------------------------------------------------------------
                      Data Types
------------------------------------------------------------------------------*/

typedef enum {
  CODING_CRYPTO_VERIFIED = 0,
  CODING_CRYPTO_NOT_VERIFIED = 1
} Coding_Crypto_VerifyState;


/*------------------------------------------------------------------------------
                      Global Function Declarations
------------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

#define Coding_START_SEC_CODE
#include "Coding_MemMap.h" /* PRQA S 5087 */

extern Coding_Crypto_VerifyState Coding_Crypto_SignatureCheck(uint8 codingAreaIdx, const uint8* cps);

#define Coding_STOP_SEC_CODE
#include "Coding_MemMap.h" /* PRQA S 5087 */

#ifdef __cplusplus
}
#endif

#endif /* CODING_CRYPTOADAPTER_H_ */
