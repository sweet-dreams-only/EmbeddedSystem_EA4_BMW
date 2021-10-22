
/**
*  \file
*
*  \brief       Crypto module template
*
*  This file is the Crypto c file containing all
*  standard certificate handling operations
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

#include "Crypto_Certificate_Intern.h"
#include <string.h>
#include "Crypto_Version.h"

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!Crypto_CHECK_VERSION(5,2,0))
#error "Version of Crypto_CertificateHandling.c does not match the version of the module!"
#endif

/*------------------------------------------------------------------------------
                      Global Functions
------------------------------------------------------------------------------*/



#define Crypto_START_SEC_CODE
#include "Crypto_MemMap.h"

/**
 * Parse a DER encoding of a value and return the length of the value and its starting position in the encoding.
 *
 * \param[in]  DEREncoding    DER encoding of a value
 * \param[out] ValueLengthPtr length of the value
 * \param[out] ValueStartPtr  starting position of the value
 *
 * \retval CRYPTO_E_OK      the information could be extracted
 * \retval CRYPTO_E_NOK     the DER encoding could not be parsed
 *
 * \pre 'DEREncoding' is a valid pointer (not checked)
 * \pre 'ValueLengthPtr' is a valid pointer (not checked)
 * \pre 'ValueStartPtr' is a valid pointer (not checked)
 *
 * \post The variable pointed to by 'ValueLengthPtr' contains the length of
 *       the value, or CRYPTO_E_NOK is returned.
 * \post The variable pointed to by 'ValueStartPtr' contains the starting position
 *       of the value in the DER encoding, or CRYPTO_E_NOK is returned.
 */

Crypto_ReturnType Crypto_DEREncodingGetInfo(const uint8  *DEREncoding,
                                            uint16 *valueLengthPtr,
                                            uint16 *valueStartPtr)
{
  Crypto_ReturnType       returnValue = CRYPTO_E_OK;  /* the return value of the function */
  uint16                  Pos    = 0;                 /* the current position in the encoding */
  uint16                  Length = 0;                 /* the length of the encoded value */

  /* We skip the tag of the encoding. */
  Pos++;

  /* The length is parsed. */
  if (DEREncoding[Pos] < (uint8)0x7F)
  {
    /* length information in one byte */
    Length = (uint16)DEREncoding[Pos];
    Pos++;
  }
  else if (DEREncoding[Pos] == (uint8)0x81)
  {
    /* length information in two bytes */
    Pos++;
    Length = (uint16)DEREncoding[Pos];
    Pos++;
  }
  else if (DEREncoding[Pos] == (uint8)0x82)
  {
    /* length information in three bytes */
    Pos++;
    Length = (uint16)((uint16)DEREncoding[Pos] * (uint16)0x100) +
             (uint16)DEREncoding[Pos + 1];
    Pos += 2;
  }
  else
  {
    /* Length information in more than three bytes is not       */
    /* supported.                                               */
    returnValue = CRYPTO_E_NOK ;
  }

  *valueStartPtr  = Pos;
  *valueLengthPtr = Length;

  return returnValue;
}

/**
 * Skip the DER encoding of a value.
 *
 * \param[in]  DEREncoding          DER encoding of the TBSCertificate
 * \param[out] DEREncodingLengthPtr length of the encoding
 *
 * \retval CRYPTO_E_OK    the encoding could be skipped
 * \retval CRYPTO_E_NOK   the DER encoding could not be parsed
 *
 * \pre 'DEREncoding' is a valid pointer (not checked)
 * \pre 'DEREncodingLengthPtr' is a valid pointer (not checked)
 *
 * \post The variable pointed to by 'DEREncodingLengthPtr' contains the length of
 *       the DER encoding of the value, or CRYPTO_E_NOK is returned.
 */

Crypto_ReturnType Crypto_DEREncodingSkip (const uint8  *DEREncoding,
                                          uint16 *DEREncodingLengthPtr)
{
  Crypto_ReturnType retVal;
  uint16            valueStartPos;
  uint16            valueLength;

  retVal = Crypto_DEREncodingGetInfo( DEREncoding, &valueLength,&valueStartPos);

  *DEREncodingLengthPtr = valueLength + valueStartPos;

  return  retVal;
}



/**
 * Extract the serial number from the given encoding.
 *
 * \param[in]  SerialNr          DER encoding of the serial number
 * \param[out] SerialNrLengthPtr length of the encoding
 * \param[out] SerialNrValue     serial number
 *
 * \retval CRYPTO_E_OK    the serial number could be extracted
 * \retval CRYPTO_E_NOK   the encoding could not be parsed or the serial number is too long
 *
 * \pre 'SerialNr' is a valid pointer (not checked)
 * \pre 'SerialNrLengthPtr' is a valid pointer (not checked)
 * \pre 'SerialNrValue' is a valid pointer (not checked)
 *
 * \post The variable pointed to by 'SerialNrLengthPtr' contains the length of
 *       the encoding of the serial number, or CRYPTO_E_NOK is returned
 * \post The variable pointed to by 'SerialNrValue' contains the serial number,
 *       or CRYPTO_E_NOK is returned
 */

Crypto_ReturnType Crypto_SerialNumberExtract( uint8  *SerialNr,
                                              uint16 *SerialNrLengthPtr,
                                              uint8*  SerialNrValue)
{
  Crypto_ReturnType RetVal;
  uint16            Pos; /* the current position in the encoding of the serial number*/
  uint16            Length;                       /* the length of the serial number */
  uint16            NrOfPadBytes;                /* the number of padding zero bytes */
  uint16            i;                                               /* loop counter */

  RetVal = Crypto_DEREncodingGetInfo(SerialNr, &Length, &Pos);

  *SerialNrLengthPtr = Pos + Length;

  if(CRYPTO_E_OK == RetVal)
  {

    /* The serial number is encoded as an integer. An integer can start     */
    /* with a zero byte. If this is the case, skip it.                      */
    if( 0x00 == SerialNr[Pos])
    {
      Pos++;
      Length--;
    }

    /* The serial number must be SWT_FSCSID_LEN bytes long. If the given  */
    /* serial number is shorter, it is padded with zero bytes at the        */
    /* beginning. If it is longer, the certificate is invalid.              */
    if ( (uint16)Crypto_FSCSID_LEN >= Length )
    {
      NrOfPadBytes = (uint16)Crypto_FSCSID_LEN - Length;

      for ( i = 0; i < NrOfPadBytes ; i++ )
      {
        SerialNrValue[i] = 0;
      }

      /* Copy the serial number to the return buffer. */
      (void)memcpy( &SerialNrValue[NrOfPadBytes],
                    &SerialNr[Pos],
                    (size_t)Length );

    }
    else
    {
      RetVal = CRYPTO_E_NOK;
    }
  }

  return RetVal;
}


/**
 *  Extract position and length of the field Validity Begin and Validity End
 *  of a certificate's validity element.
 *
 * \param[in]  validity             pointer to the validity element of the certificate.
 * \param[out] validityLength       Length of the element.
 * \param[out] result
 *
 * \retval CRYPTO_E_OK    the validity could be extracted.
 * \retval CRYPTO_E_NOK   the encoding could not be parsed.
 *
 * \pre validity is a valid pointer (not checked).
 * \pre validityLength is a valid pointer (not checked).
 * \pre result is a valid pointer (not checked).
 *
 * \post the variable pointed by 'result' contains a pointer to both validity begin/end
 *  fields of the certificate and to variables contain the corresponding lengths, or
 *  CRYPTO_E_NOK is returned.
 *
 * */

Crypto_ReturnType Crypto_DEREncodingGetValidity(const uint8              *validity,
                                                uint16                   *validityLength,
                                                Crypto_certifParseResult *result)
{
  uint16              position;
  uint16              positionElement;
  uint16              length;
  Crypto_ValidityType validityElement;
  Crypto_ReturnType   retVal;

  position = 0;
  length   = 0;

  retVal = Crypto_DEREncodingGetInfo(validity, &length, &position);

  validityElement = CRYPTO_CERT_VALID_NOT_BEFORE;

  while ( (validityElement < CRYPTO_CERT_VALID_END ) &&
          ( CRYPTO_E_OK == retVal ))
  {
    switch ( validityElement )
    {
      case CRYPTO_CERT_VALID_NOT_BEFORE :
        retVal = Crypto_DEREncodingGetInfo( &validity[position], &length, &positionElement );
        position += positionElement;

        result->validityBeginLength  = length;
        result->validityBeginPointer = &validity[position];

        position += length;
        validityElement++;
        break;

      case CRYPTO_CERT_VALID_NOT_AFTER :
        retVal = Crypto_DEREncodingGetInfo( &validity[position], &length, &positionElement );
        position += positionElement;

        result->validityEndLength   = length;
        result->validityEndPointer  = &validity[position];

        position += length;
        validityElement++;
        break;


      default :
        /* This code section should never be reached. */
        retVal = CRYPTO_E_NOK;
        break;
    }
  }

  *validityLength = position;

  return retVal;
}




/**
 *
 * This functions goes through a TBS certificate and returns pointers to each element
 * together with their length. It also returns the complete length of the TBS
 * certificate so parsing can continue.
 *
 * \param[in]  TBSCert              Pointer to the beginning of the TBS certificate.
 * \param[out] TBSCertLengthPtr     Pointer to the length of the TBS certificate (shall be set by this function).
 * \param[out] result               Pointer to the structure containing the result elements.
 *
 * \retval CRYPTO_E_OK  Parsing was successful.
 * \retval CRYPTO_E_NOK An error occurred during parsing.
 *
 * \pre cert is a valid pointer (not checked).
 * \pre result is a valid pointer (not checked).
 *
 * \post result contains correct pointers and length of each element in the TBS certificate
 *  or CRYPTO_E_NOK is returned.
 *
 **/


Crypto_ReturnType Crypto_parseTBSCertificate( const uint8               *TBSCert,
                                              uint16                    *TBSCertLengthPtr,
                                              Crypto_certifParseResult  *result)
{

  Crypto_ReturnType     returnValue;
  uint16                certificateLength;
  uint16                currentPosition;
  uint16                elementPosition;
  uint16                elementLength;
  Crypto_TBSElementType certificateElement;


  /* Acquire length of the certificate and position of the first element */

  returnValue = Crypto_DEREncodingGetInfo(TBSCert, &certificateLength, &currentPosition);

  /* Compute the length of the TBSCertificate. */
  *TBSCertLengthPtr = certificateLength + currentPosition;

  /* while the current element is not the end of the certificate, we read every element. */
  certificateElement = CRYPTO_CERT_VERSION;

  while ( certificateElement < CRYPTO_CERT_END &&
          returnValue == CRYPTO_E_OK
          ) {

    switch (certificateElement) {
      case CRYPTO_CERT_SERIALNUMBER :
        returnValue = Crypto_DEREncodingGetInfo(&TBSCert[currentPosition], &elementLength, &elementPosition);

        currentPosition += elementPosition;

        result->serialNumberPointer = &TBSCert[currentPosition];
        result->serialNumberLength = elementLength;

        currentPosition += elementLength;
        certificateElement++;
        break;
      case CRYPTO_CERT_SIGNATURE :

        returnValue = Crypto_DEREncodingGetInfo(&TBSCert[currentPosition], &elementLength, &elementPosition);

        currentPosition += elementPosition;

        result->signaturePointer = &TBSCert[currentPosition];
        result->signatureLength  = elementLength;

        currentPosition += elementLength;
        certificateElement++;
        break;

      case CRYPTO_CERT_ISSUER :

        returnValue = Crypto_DEREncodingGetInfo(&TBSCert[currentPosition], &elementLength, &elementPosition);

        currentPosition += elementPosition;

        result->issuerPointer = &TBSCert[currentPosition];
        result->issuerLength  = elementLength;

        currentPosition += elementLength;
        certificateElement++;
        break;

      case CRYPTO_CERT_VALIDITY :
        /* extract validity */

        returnValue = Crypto_DEREncodingGetValidity( &TBSCert[currentPosition], &elementLength, result);

        currentPosition += elementLength;
        certificateElement++;

      case CRYPTO_CERT_SUBJECT :
        /* pointer to subject */
      case CRYPTO_CERT_SUBJECTPKI :

      case CRYPTO_CERT_VERSION :
      case CRYPTO_CERT_EXTENSIONS :
        /* we skip these elements */
        returnValue = Crypto_DEREncodingSkip(&TBSCert[currentPosition], &elementLength);
        currentPosition += elementLength;
        certificateElement++;
        break;

      case CRYPTO_CERT_END :
      default:
        /* we should not read this line of code */
        returnValue = CRYPTO_E_NOK;
        break;

    }
  }


  return returnValue;
}




/**
 *
 * This functions goes through a complete X509 certificate and returns pointers to each element
 * together with their length.
 *
 * \param[in]  cert   X509 certificate in form of an uint8 array.
 * \param[out] result structure containing pointer and length of each element.
 *
 * \retval CRYPTO_E_OK  Parsing was successful.
 * \retval CRYPTO_E_NOK An error occurred during parsing.
 *
 * \pre cert is a valid pointer (not checked).
 * \pre result is a valid pointer (not checked).
 *
 * \post result contains correct pointers and length of each element in the X509 certificate
 *  or CRYPTO_E_NOK is returned.
 *
 * \lhref CERT_20
 *
 **/

Crypto_ReturnType Crypto_CertParse(const uint8               *cert,
                                   Crypto_certifParseResult  *result)
{
  Crypto_ReturnType       RetVal;               /* the return value of the function. */
  Crypto_X509ElementType  CertElement;          /* the current element of the cert. */
  uint16                  Length;               /* The length of the certificate. */
  uint16                  Pos;                  /* the current position in the certificate. */
  uint16                  ElementLength;        /* the length of the current element. */
  uint16                  ElementPosition;      /* the length of the current element. */
  uint16                  SubElementLength;        /* the length of the current element. */
  uint16                  SubElementPosition;      /* the length of the current element. */
  uint8                   padding;


  RetVal = Crypto_DEREncodingGetInfo(cert, &Length, &Pos);

  Length += Pos;

  /* The first element of the sequence must be a TBSCertificate. */
  CertElement = Crypto_CERT_X509_CERTIFICATE;

  /* Go through all elements of the certificate and check those elements     */
  /* which have to be checked until all elements are done or an error has    */
  /* been encountered.                                                       */

  while ((( CertElement < Crypto_CERT_X509_END )  &&
          ( RetVal == CRYPTO_E_OK )               &&
          ( Pos < Length  )))
  {
    switch (CertElement)
    {
      case Crypto_CERT_X509_CERTIFICATE  :
        RetVal = Crypto_parseTBSCertificate(&cert[Pos],
                                            &ElementLength,
                                            result);

        result->TBSCertLength = ElementLength;
        result->TBSCertPointer = &cert[Pos];

        Pos          += ElementLength;
        CertElement++;
        break;

      case Crypto_CERT_X509_SIGNATURE_ALGO :
        /* The signature algorithm is an object id encapsulated in a sequence */

        /* Reading the sequence length */
        RetVal = Crypto_DEREncodingGetInfo(&cert[Pos],
                                           &ElementLength,
                                           &ElementPosition);
        Pos += ElementPosition;
        if (RetVal == CRYPTO_E_OK)
        {

          /* Getting object ID length. */
          RetVal = Crypto_DEREncodingGetInfo(&cert[Pos],
                                             &SubElementLength,
                                             &SubElementPosition);

          result->signatureAlgorithmPointer = &cert[Pos + SubElementPosition];
          result->signatureAlgorithmLength  = SubElementLength;

        }
        Pos += ElementLength;
        CertElement++;

        break;

      case Crypto_CERT_X509_SIGNATURE :

        RetVal = Crypto_BitString_GetInfo( &cert[Pos],
                                           &ElementLength,
                                           &ElementPosition,
                                           &padding );

        /* padding should not necessary in a certificate (all signatures size shall be in BYTES) */
        /* For 521 bits signature, the size of each integer being part of the signature is still in bytes  */
        if(padding != 0 )
        {
          return CRYPTO_E_NOK;
        }

        Pos += ElementPosition;

        result->signaturePointer = &cert[Pos];
        result->signatureLength  = ElementLength;

        Pos += ElementLength;
        CertElement++;
        break;


      case Crypto_CERT_X509_END :
      default:
        /* Skip these elements. */
        RetVal = Crypto_DEREncodingSkip(&cert[Pos], &ElementLength);
        Pos += ElementLength;
        CertElement++;
        break;
    }
  }
  return RetVal;
}


/**
 *  Parse a bit string and return the corresponding information.
 *  \param[in]  bitString            The DER encoded BIT STRING
 *  \param[out] bitStringLength      The size of the DER BIT STRING
 *  \param[out] bitStringStartPtr    Starting position of the bit string.
 *  \param[out] numberOfpaddingbits  Number of padding (unused) bits at the end of the last Byte.
 *
 *  @return CRYPTO_E_OK if successful
*/
Crypto_ReturnType Crypto_BitString_GetInfo(const uint8 *bitString,
                                           uint16*      bitStringLength,
                                           uint16*      bitStringStartPtr,
                                           uint8*       numberOfPaddingBits)
{

  /* check for 0x03 (i.e. the correct tag for a bitString). */
  if ((bitString[0] & 0x1F) != 0x03) {
    return CRYPTO_E_NOK;
  }

  Crypto_DEREncodingGetInfo(bitString, bitStringLength, bitStringStartPtr);

  *numberOfPaddingBits = bitString[*bitStringStartPtr] & 7;

  /* we skip the padding. */
  (*bitStringStartPtr)++;
  (*bitStringLength)--;


  return CRYPTO_E_OK;

}




/**
 *
 * This functions goes through a DER-Encoded ECDSA Signature and returns in the format used by the
 * ECDSA verify algorithm.
 *
 * \param[in]  signaturePointer     Pointer to the 1st element of the ECDSA signature in the x509 certificate.
 * \param[out] formattedSignature   Result of the parse.
 * \param[out] signatureLength      Length of a signature element in bytes.
 *
 * \retval CRYPTO_E_OK  Parsing was successful.
 * \retval CRYPTO_E_NOK An error occurred during parsing.
 *
 * \pre signaturePointer is a valid pointer (not checked).
 * \pre formattedSignature is a valid pointer (not checked).
 *
 * \post formattedSignature contains a pointer to a correctly parsed information
 *  or CRYPTO_E_NOK is returned.
 *
 * \lhref CERT_1173
 *
 **/
Crypto_ReturnType Crypto_EcdsaSignatureParse(const uint8 *signaturePointer,
                                             uint8       *formattedSignature,
                                             uint16      *signatureLength)
{
  /* ECDSA Signature is stored  as
   *   SEQUENCE(2 elem)
   *     INTEGER  R
   *     INTEGER  S
   *
   * */

  Crypto_ReturnType retVal;
  uint16 elementLength;
  uint16 elementStart;
  uint16 currentOffset;

  /* we start at the position 0 */
  currentOffset = 0;

  /* decode info of the sequence  and skip the headers */
  retVal = Crypto_DEREncodingGetInfo(&signaturePointer[currentOffset], &elementLength, &elementStart);
  if(retVal != CRYPTO_E_OK )
  {
    return CRYPTO_E_NOK;
  }
  currentOffset += elementStart;

  /* decode r */
  retVal = Crypto_DEREncodingGetInfo(&signaturePointer[currentOffset], &elementLength, &elementStart);
  if(retVal != CRYPTO_E_OK )
  {
    return CRYPTO_E_NOK;
  }
  /*
   * Integer certificate format is signed but target format is not.
   * if the integer size is in byte, the first byte contains only the sign (positive) and can be skipped. */
  currentOffset += elementStart;
  if (signaturePointer[currentOffset] == 0x00)
  {
    /* contains only the sign - can be skipped */
    currentOffset++;
    elementLength--;
  }
  memcpy(formattedSignature,&signaturePointer[currentOffset], elementLength);
  currentOffset += elementLength ;

  /* decode S */
  retVal = Crypto_DEREncodingGetInfo(&signaturePointer[currentOffset], &elementLength, &elementStart);
  if(retVal != CRYPTO_E_OK )
  {
    return CRYPTO_E_NOK;
  }
  /*
   * integer certificate format is signed but target format is not.
   * we increment the current offset to skip the header and the first byte (containing the sign)
   * and therefore reduce the size of the element length */

  currentOffset += elementStart;
  if (signaturePointer[currentOffset] == 0x00)
  {
    /* contains only the sign - can be skipped */
    currentOffset++;
    elementLength--;
  }

  memcpy(&formattedSignature[elementLength],&signaturePointer[currentOffset], elementLength);

  *signatureLength = elementLength;
  return CRYPTO_E_OK;

}

#define Crypto_STOP_SEC_CODE
#include "Crypto_MemMap.h"