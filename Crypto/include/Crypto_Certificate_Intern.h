/**
*  \file
*
*  \brief       BMW Crypto Library
*
*  This file is the internal header of the Certificate operations used by the Crypto
*  lib for usage in the BMW AUTOSAR Core.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.2.0
*
*/


#ifndef CRYPTO_CERTIFICATE_INTERN_H
#define CRYPTO_CERTIFICATE_INTERN_H

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "Crypto_Common_Intern.h"
#include "Crypto_Certificate.h"
#include "Crypto_Version.h"


/*------------------------------------------------------------------------------
                              Macros
------------------------------------------------------------------------------*/
/* check version of the module */
#if (!Crypto_CHECK_VERSION(5,2,0))
#error "Version of Certificate_Intern.h does not match the version of the module!"
#endif

#define Crypto_FSCSID_LEN 8U


/*------------------------------------------------------------------------------
                      Data Types
------------------------------------------------------------------------------*/


/** The elements of an X.509 v3 certificate according to RFC 2459, chapter 4.1.*/
typedef enum
{
  Crypto_CERT_X509_CERTIFICATE,
  Crypto_CERT_X509_SIGNATURE_ALGO,
  Crypto_CERT_X509_SIGNATURE,
  Crypto_CERT_X509_END
}Crypto_X509ElementType;

/** The elements of a TBSCertificate according to RFC 2459, chapter 4.1. */
typedef enum
{
  CRYPTO_CERT_VERSION,
  CRYPTO_CERT_SERIALNUMBER,
  CRYPTO_CERT_SIGNATURE,
  CRYPTO_CERT_ISSUER,
  CRYPTO_CERT_VALIDITY,
  CRYPTO_CERT_SUBJECT,
  CRYPTO_CERT_SUBJECTPKI,
  CRYPTO_CERT_EXTENSIONS,
  CRYPTO_CERT_END
}Crypto_TBSElementType;


/** The elements of the Validity field according to RFC 2459, chapter 4.1. */
typedef enum
{
  CRYPTO_CERT_VALID_NOT_BEFORE,
  CRYPTO_CERT_VALID_NOT_AFTER,
  CRYPTO_CERT_VALID_END
}Crypto_ValidityType;

/* the type of an encoding of a date. */
typedef enum
{
  Crypto_DATE_FSC_TIME = 0x00,                 /* date format as used in FSCs */
  Crypto_DATE_UTC_TIME = 0x17,             /* UTCTime, see X.690 chapter 11.8 */
  Crypto_DATE_GENERALIZED_TIME = 0x18 /* Generalized Time, X.690 chapter 11.7 */
}Crypto_DateType;




/*------------------------------------------------------------------------------
                      Global Function Declarations
------------------------------------------------------------------------------*/



Crypto_ReturnType Crypto_parseTBSCertificate(const uint8              *TBSCert,
                                             uint16                   *TBSCertLengthPtr,
                                             Crypto_certifParseResult *result);


Crypto_ReturnType Crypto_DEREncodingGetInfo(const uint8  *DEREncoding,
                                            uint16       *valueLengthPtr,
                                            uint16       *valueStartPtr);


Crypto_ReturnType Crypto_DEREncodingSkip (const uint8  *DEREncoding,
                                          uint16       *DEREncodingLengthPtr);

Crypto_ReturnType Crypto_BitString_GetInfo(const uint8 *bitString,
                                           uint16*      bitStringLength,
                                           uint16*      bitStringStartPtr,
                                           uint8*       numberOfpaddingbits);



#endif /* CRYPTO_CERTIFICATE_INTERN_H */
