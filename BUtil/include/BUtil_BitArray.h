/**
*  \file
*  \ingroup API
*
*  \brief       Access Bit Arrays.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.0.3
*
*/
/*----------------------------------------------------------------------------*/

#ifndef BUTIL_BITARRAY_H_
#define BUTIL_BITARRAY_H_


/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/

/* Violation of MISRA rule 19.7, Reason: C90 does not support inline
 * functions, see PRQA 3453
 */


/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/

#include "BUtil_Version.h"


/*------------------------------------------------------------------------------
                      Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!BUtil_CHECK_VERSION(5,0,3))
   #error "Version of BUtil_BitArray.h does not match the version of the module!"
#endif


/****** Macros for multi-byte-bit-array access *********************************/

/**
 * Calculate the number of bytes that are needed for the bit field to store the
 * number of elements
 */
#define BUtil_CalcRequiredBytesForMultiByteBitArray(elements)                 \
            ( ( ( (elements) - 0x01u ) / 0x08u ) + 0x01u ) /* PRQA S 3453 */


/**
 * Calculate the index of the byte-level that holds the bit for the given entry:
 * Equivalent to 'element / 8'
 */
#define BUtil_CalcArrayByteLevel(element)                                         \
            ( (element) >> 3 ) /* PRQA S 3453 */

/**
 * Calculate the special bit position in the corresponding byte of the
 * multi-byte-bit-array, that holds the bits for the given entry:
 * Equivalent to 'element % 8'
 * Bit 0 ... 7 is equivalent to LSB ... MSB
 */
#define BUtil_CalcBitIndex(element)                                                \
            ( (uint8)(element) & (uint8)0x07u ) /* PRQA S 3453 */


/**
 * Set the bit number 'element' in the multi-byte-bit-array 'array' (to '1')
 */
#define BUtil_SetBitInMultiByteBitArray(array,element)                         \
            ( ((array)[BUtil_CalcArrayByteLevel(element)]) |=            \
              ((uint8)(0x01u << BUtil_CalcBitIndex(element)))                      \
            )              /* PRQA S 3453 */

/**
 * Clear the bit number 'element' in the multi-byte-bit-array 'array' (to '0')
 */
#define BUtil_ClearBitInMultiByteBitArray(array,element)                       \
            ( ((array)[BUtil_CalcArrayByteLevel(element)]) &=            \
              ((uint8)~(0x01u << BUtil_CalcBitIndex(element)))                     \
            )              /* PRQA S 3453 */

/**
 * Get the value ('0' or '1') of the the bit number 'element' in the multi-byte-
 * bit-array 'array'
 */
#define BUtil_GetBitInMultiByteBitArray(array,element)                         \
     (uint8)(                                                                  \
       ((uint8)(((uint8)((array)[BUtil_CalcArrayByteLevel(element)])) >> \
              BUtil_CalcBitIndex(element))) & (uint8)(0x01u)                       \
            )              /* PRQA S 3453 */


#endif /* BUTIL_BITARRAY_H_ */
