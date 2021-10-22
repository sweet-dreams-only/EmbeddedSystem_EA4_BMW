
/**
*  \file
*
*  \brief       BMW Crypto Library
*
*  This file is the extern definition header file of the generic certificate part of the
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
#ifndef CRYPTO_CERTIFICATE_H
#define CRYPTO_CERTIFICATE_H

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "BUtil/PlatformTypes.h"
#include "Crypto_Common.h"
#include "Crypto_KeyManagement.h"
#include "Crypto_Version.h"

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!Crypto_CHECK_VERSION(5,2,0))
#error "Version of Crypto_Certificate.h does not match the version of the module!"
#endif


#ifdef __cplusplus
extern  "C" {
#endif


/** the target structure containing the result of the parsing. */
typedef struct {

  const uint8 *serialNumberPointer;
  uint16 serialNumberLength;
  const uint8 *issuerPointer;
  uint16 issuerLength;
  const uint8 *validityBeginPointer;
  uint16 validityBeginLength;
  const uint8 *validityEndPointer;
  uint16 validityEndLength;
  const uint8 *subjectPointer;
  uint16 subjectLength;
  const uint8 *subjectPKIPointer;
  uint16 subjectPKILength;
  const uint8 *signatureAlgorithmPointer;
  uint16 signatureAlgorithmLength;
  const uint8 *signaturePointer;
  uint16 signatureLength;

  /* TBS Certificate */
  const uint8 *TBSCertPointer;
  uint16 TBSCertLength;

} Crypto_certifParseResult;


Crypto_ReturnType Crypto_CertParse(const uint8 *cert,
                                   Crypto_certifParseResult *result);

Crypto_ReturnType Crypto_EcdsaSignatureParse(const uint8  *signaturePointer,
                                                   uint8  *formattedSignature,
                                                   uint16 *signatureLength);

#ifdef __cplusplus
}
#endif


#endif /* CRYPTO_CERTIFICATE_H */
