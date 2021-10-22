/**
*  \file
*
*  \brief       Read Address Format.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.0.3
*
*/

/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/

/* Violation of MISRA rule 19.1, Reason: Including StbMB_MemMap.h is necessary throughout
   the file according to memory abstraction, see PRQA: 5087 */


/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "BUtil_AddressFormat.h"

#include "BUtil_ByteMask.h"
#include "BUtil_BitArray.h"
#include "BUtil_Version.h"

/*------------------------------------------------------------------------------
                      Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!BUtil_CHECK_VERSION(5,0,3))
   #error "Version of BUtil_AddressFormat.c does not match the version of the module!"
#endif


/*------------------------------------------------------------------------------
                      Global Functions
-------------------------------------------------------------------------------*/

#define BUtil_START_SEC_CODE
#include "BUtil_MemMap.h" /* PRQA S 5087 */

/**
 * Convert a address and/or a length from an diagnostic
 * request to variables.
 *
 * \param[in] reqDataPtr              request data buffer at the position of
 *                                    the AddressAndLengthByFormatId byte
 * \param[in] addressOrLengthSize     length that the address must take in
 *                                    the request
 * \param[in] addressOrLengthFormatId Address-/ Length-/ AddressAndLenght-
 *                                    FormatIdentifier
 * \param[out] pAddress               taking the address
 * \param[out] pLength                taking the length
 *
 * \retval BUTIL_E_AF_OK                valid address and/or length
 * \retval BUTIL_E_AF_WRONG_FORMAT      invalid address and length
 *                                    format identifier
 * \retval BUTIL_E_AF_WRONG_SIZE        invalid request length
 *
 * \remark when only a address or a length is requested
 *         (AddressAndLenghtFormatIdentifier 0x0? or 0x?0) the
 *         function can be called with the same parameter for
 *         pAddress and pLength
 *
 */
BUtil_AddressFormatReturnType BUtil_GetAddressAndLengthByFormatIdentifier
      (
          const BUtil_FormatBuffer* const reqDataPtr,
          const uint8                     addressOrLengthSize,
          const BUtil_FormatIdentifier    addressOrLengthFormatId,
          uint32* const                   pAddress,
          uint32* const                   pLength
      )
{
   const uint8 addressFormatIdentifier = (*reqDataPtr)[0] &  (uint8)0x0Fu;
   const uint8 lengthFormatIdentifier  = (*reqDataPtr)[0] >> (uint8)0x04u;

   BUtil_AddressFormatReturnType retVal = BUTIL_E_AF_OK;
   uint8_least idx = 0;

   if ( (*reqDataPtr)[idx] != addressOrLengthFormatId )
   {
      retVal = BUTIL_E_AF_WRONG_FORMAT;
   }
   else
   {
      const uint8 tmpAddressOrLengthSize = addressFormatIdentifier +
                                           lengthFormatIdentifier;
      ++idx;
      if ( addressOrLengthSize != tmpAddressOrLengthSize )
      {
         retVal = BUTIL_E_AF_WRONG_SIZE;
      }
      else
      {
            if ( addressFormatIdentifier != (uint8)0x00u )
            {
               *pAddress = BUtil_Make32Bit (
                                        (*reqDataPtr)[idx+0],
                                        (*reqDataPtr)[idx+1],
                                        (*reqDataPtr)[idx+2],
                                        (*reqDataPtr)[idx+3]
                                     );
               idx+=4;
            }

            if ( lengthFormatIdentifier != (uint8)0x00u )
            {
               *pLength = BUtil_Make32Bit (
                                       (*reqDataPtr)[idx+0],
                                       (*reqDataPtr)[idx+1],
                                       (*reqDataPtr)[idx+2],
                                       (*reqDataPtr)[idx+3]
                                    );
            }

            retVal = BUTIL_E_AF_OK;
      }
   }

   return retVal;
} /* end of function 'BUtil_GetAddressAndLengthByFormatIdentifier'                  */

#define BUtil_STOP_SEC_CODE
#include "BUtil_MemMap.h" /* PRQA S 5087 */
