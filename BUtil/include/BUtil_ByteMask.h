/**
*  \file
*  \ingroup API
*
*  \brief       Access Single Bytes of Words.
*
 * \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.0.3
*
*/

#ifndef BUTIL_BYTEMASK_H_
#define BUTIL_BYTEMASK_H_

/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/

/* Violation of MISRA rule 19.7, Reason: C90 does not support inline
 * functions, see PRQA 3453
 */
/*
   MISRA-C:2004 Rule 19.10: The macro contains multiple statements capsulated
                            by a do..while(0) loop.
   Reference (PRQA): 3410
*/

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/

#include "BUtil_Version.h"
#include "BUtil/PlatformTypes.h"


/*------------------------------------------------------------------------------
                      Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!BUtil_CHECK_VERSION(5,0,3))
   #error "Version of BUtil_ByteMask.h does not match the version of the module!"
#endif

/**
 * Returns a 16 bit word composed from given high and low byte.
 */
#define BUtil_Make16Bit(hiByte,loByte)   ((uint16)((((uint16)(hiByte))<<8)|    \
                                         ((uint16)(loByte)))) /* PRQA S 3453 */

/**
 * Returns a 32 bit word composed from four given bytes.
 */
#define BUtil_Make32Bit(hiHiByte,hiLoByte,loHiByte,loLoByte)                   \
                                         ((uint32)((((uint32)(hiHiByte))<<24)| \
                                         (((uint32)(hiLoByte))<<16)|           \
                                         (((uint32)(loHiByte))<<8) |           \
                                         ((uint32)(loLoByte)))) /* PRQA S 3453 */

/**
 * Returns a 64 bit word composed from four given bytes.
 */
#define BUtil_Make64Bit(hiHiHiByte,hiHiLoByte,hiLoHiByte,hiLoLoByte,loHiHiByte,loHiLoByte,loLoHiByte,loLoLoByte) \
                                         ((uint64)((((uint64)(hiHiHiByte))<<56)| \
                                         (((uint64)(hiHiLoByte))<<48)| \
                                         (((uint64)(hiLoHiByte))<<40)| \
                                         (((uint64)(hiLoLoByte))<<32)| \
                                         (((uint64)(loHiHiByte))<<24)| \
                                         (((uint64)(loHiLoByte))<<16)| \
                                         (((uint64)(loLoHiByte))<<8) | \
                                         (((uint64)(loLoLoByte))))) /* PRQA S 3453 */

/**
 * Returns the high byte of the given 16 bit word.
 */
#define BUtil_GetHiByte(data)            ((uint8)(((uint16)(data))>>8)) /* PRQA S 3453 */

/**
 * Returns the low byte of the given 16 bit word.
 */
#define BUtil_GetLoByte(data)            ((uint8)(data)) /* PRQA S 3453 */

/**
 * Returns the most significant byte of the given 32 bit word
 */
#define BUtil_GetHiHiByte(data)          ((uint8)(((uint32)(data))>>24)) /* PRQA S 3453 */

/**
 * Returns the second most significant byte of the given 32 bit word
 */
#define BUtil_GetHiLoByte(data)          ((uint8)(((uint32)(data))>>16)) /* PRQA S 3453 */

/**
 * Returns the second least significant byte of the given 32 bit word
 */
#define BUtil_GetLoHiByte(data)          ((uint8)(((uint32)(data))>>8)) /* PRQA S 3453 */

/**
 * Returns the least significant byte of the given 32 bit word
 */
#define BUtil_GetLoLoByte(data)          ((uint8)(data)) /* PRQA S 3453 */

/**
 * Returns the most significant byte of the given 64 bit word
 */
#define BUtil_GetHiHiHiByte(data)        ((uint8)(((uint64)(data))>>56)) /* PRQA S 3453 */

/**
 * Returns the second most significant byte of the given 64 bit word
 */
#define BUtil_GetHiHiLoByte(data)        ((uint8)(((uint64)(data))>>48)) /* PRQA S 3453 */

/**
 * Returns the third most significant byte of the given 64 bit word
 */
#define BUtil_GetHiLoHiByte(data)        ((uint8)(((uint64)(data))>>40)) /* PRQA S 3453 */

/**
 * Returns the fourth most significant byte of the given 64 bit word
 */
#define BUtil_GetHiLoLoByte(data)        ((uint8)(((uint64)(data))>>32)) /* PRQA S 3453 */

/**
 * Returns the fourth least significant byte of the given 64 bit word
 */
#define BUtil_GetLoHiHiByte(data)        ((uint8)(((uint64)(data))>>24)) /* PRQA S 3453 */

/**
 * Returns the third least significant byte of the given 64 bit word
 */
#define BUtil_GetLoHiLoByte(data)        ((uint8)(((uint64)(data))>>16)) /* PRQA S 3453 */

/**
 * Returns the second least significant byte of the given 64 bit word
 */
#define BUtil_GetLoLoHiByte(data)        ((uint8)(((uint64)(data))>>8)) /* PRQA S 3453 */

/**
 * Returns the least significant byte of the given 64 bit word
 */
#define BUtil_GetLoLoLoByte(data)        ((uint8)(data)) /* PRQA S 3453 */

/**
 * Converts a 8 bit BCD value to
 * decimal system
 */
#define BUtil_BCD2DEC(BCD) (uint8)                  \
   (                                                \
      ((((BCD)>>4u) & 0x0Fu) * 10u) +               \
      (  (BCD)      & 0x0Fu)                        \
   ) /* PRQA S 3453 */

/**
 * Check, if the given digit is a BCD
 * value
 */
#define BUtil_IsBCDDigit(digit)    (((uint8)(digit)) <= (uint8)0x09u) /* PRQA S 3453 */

/**
 * Check, if the given byte is a BCD
 * encoded value
 */
#define BUtil_ByteIsBCDValue(Byte)                  \
   (                                                \
      (BUtil_IsBCDDigit(((uint8)(Byte)) >> (uint8)4u)) && \
      (BUtil_IsBCDDigit(((uint8)(Byte)) &  (uint8)0x0Fu)) \
   ) /* PRQA S 3453 */

/**
 * Returns a 64bit value stored in little endian format
 * in a uint8 array
 *
 * Note: Using this macro you need to suppress PRQA Message 0489 because of pointer
 * arithmetic which is not compliant to MISRA 17.4
 */
/* PRQA S 3410,3453 PutGet64Bit */
#define BUtil_Get64BitLittleEndian(pointer) \
   (                                        \
      BUtil_Make64Bit(                      \
         *(pointer + 7),                    \
         *(pointer + 6),                    \
         *(pointer + 5),                    \
         *(pointer + 4),                    \
         *(pointer + 3),                    \
         *(pointer + 2),                    \
         *(pointer + 1),                    \
         *(pointer + 0)                     \
      )                                     \
   )

/**
 * Returns a 64bit value stored in big endian format
 * in a uint8 array
 *
 * Note: Using this macro you need to suppress PRQA Message 0489 because of pointer
 * arithmetic which is not compliant to MISRA 17.4
 */
#define BUtil_Get64BitBigEndian(pointer) \
   (                                     \
      BUtil_Make64Bit(                   \
         *(pointer + 0),                 \
         *(pointer + 1),                 \
         *(pointer + 2),                 \
         *(pointer + 3),                 \
         *(pointer + 4),                 \
         *(pointer + 5),                 \
         *(pointer + 6),                 \
         *(pointer + 7)                  \
      )                                  \
   )

/**
 * Returns a 64bit value stored in little endian format
 * in a uint8 array
 *
 * Note: Using this macro you need to suppress PRQA Message 0489 because of pointer
 * arithmetic which is not compliant to MISRA 17.4
 */
#define BUtil_Put64BitLittleEndian(pointer, value) \
   do{                                             \
      *(pointer + 7) = BUtil_GetHiHiHiByte(value);   \
      *(pointer + 6) = BUtil_GetHiHiLoByte(value);   \
      *(pointer + 5) = BUtil_GetHiLoHiByte(value);   \
      *(pointer + 4) = BUtil_GetHiLoLoByte(value);   \
      *(pointer + 3) = BUtil_GetLoHiHiByte(value);   \
      *(pointer + 2) = BUtil_GetLoHiLoByte(value);   \
      *(pointer + 1) = BUtil_GetLoLoHiByte(value);   \
      *(pointer + 0) = BUtil_GetLoLoLoByte(value);   \
   } while(0)

/**
 * Returns a 64bit value stored in big endian format
 * in a uint8 array
 *
 * Note: Using this macro you need to suppress PRQA Message 0489 because of pointer
 * arithmetic which is not compliant to MISRA 17.4
 */
#define BUtil_Put64BitBigEndian(pointer, value)  \
   do {                                          \
      *(pointer + 0) = BUtil_GetHiHiHiByte(value); \
      *(pointer + 1) = BUtil_GetHiHiLoByte(value); \
      *(pointer + 2) = BUtil_GetHiLoHiByte(value); \
      *(pointer + 3) = BUtil_GetHiLoLoByte(value); \
      *(pointer + 4) = BUtil_GetLoHiHiByte(value); \
      *(pointer + 5) = BUtil_GetLoHiLoByte(value); \
      *(pointer + 6) = BUtil_GetLoLoHiByte(value); \
      *(pointer + 7) = BUtil_GetLoLoLoByte(value); \
   } while(0)

/* PRQA L:PutGet64Bit */

/**
 * Returns a 32bit value stored in little endian format
 * in a uint8 array
 *
 * Note: Using this macro you need to suppress PRQA Message 0489 because of pointer
 * arithmetic which is not compliant to MISRA 17.4
 */
/* PRQA S 3410,3453 PutGet32Bit */
#define BUtil_Get32BitLittleEndian(pointer) \
   (                                        \
      BUtil_Make32Bit(                      \
         *(pointer + 3),                    \
         *(pointer + 2),                    \
         *(pointer + 1),                    \
         *(pointer + 0)                     \
      )                                     \
   )

/**
 * Returns a 32bit value stored in big endian format
 * in a uint8 array
 *
 * Note: Using this macro you need to suppress PRQA Message 0489 because of pointer
 * arithmetic which is not compliant to MISRA 17.4
 */
#define BUtil_Get32BitBigEndian(pointer) \
   (                                     \
      BUtil_Make32Bit(                   \
         *(pointer + 0),                 \
         *(pointer + 1),                 \
         *(pointer + 2),                 \
         *(pointer + 3)                  \
      )                                  \
   )

/**
 * Returns a 32bit value stored in little endian format
 * in a uint8 array
 *
 * Note: Using this macro you need to suppress PRQA Message 0489 because of pointer
 * arithmetic which is not compliant to MISRA 17.4
 */
#define BUtil_Put32BitLittleEndian(pointer, value) \
   do{                                             \
      *(pointer + 3) = BUtil_GetHiHiByte(value);   \
      *(pointer + 2) = BUtil_GetHiLoByte(value);   \
      *(pointer + 1) = BUtil_GetLoHiByte(value);   \
      *(pointer + 0) = BUtil_GetLoLoByte(value);   \
   } while(0)

/**
 * Returns a 32bit value stored in big endian format
 * in a uint8 array
 *
 * Note: Using this macro you need to suppress PRQA Message 0489 because of pointer
 * arithmetic which is not compliant to MISRA 17.4
 */
#define BUtil_Put32BitBigEndian(pointer, value)  \
   do {                                          \
      *(pointer + 0) = BUtil_GetHiHiByte(value); \
      *(pointer + 1) = BUtil_GetHiLoByte(value); \
      *(pointer + 2) = BUtil_GetLoHiByte(value); \
      *(pointer + 3) = BUtil_GetLoLoByte(value); \
   } while(0)

/* PRQA L:PutGet32Bit */
/**
 * Returns a 32bit value stored in little endian format
 * in a uint8 array
 *
 * Note: Using this macro you need to suppress PRQA Message 0489 because of pointer
 * arithmetic which is not compliant to MISRA 17.4
 */
/* PRQA S 3410,3453 PutGet16Bit */
#define BUtil_Get16BitLittleEndian(pointer) \
   (                                        \
      BUtil_Make16Bit(                      \
         *(pointer + 1),                    \
         *(pointer + 0)                     \
      )                                     \
   )


/**
 * Returns a 16bit value stored in big endian format
 * in a uint8 array
 *
 * Note: Using this macro you need to suppress PRQA Message 0489 because of pointer
 * arithmetic which is not compliant to MISRA 17.4
 */
#define BUtil_Get16BitBigEndian(pointer) \
   (                                     \
      BUtil_Make16Bit(                   \
         *(pointer + 0),                 \
         *(pointer + 1)                  \
      )                                  \
   )

/**
 * Returns a 16bit value stored in little endian format
 * in a uint8 array
 *
 * Note: Using this macro you need to suppress PRQA Message 0489 because of pointer
 * arithmetic which is not compliant to MISRA 17.4
 */
#define BUtil_Put16BitLittleEndian(pointer, value) \
   do {                                            \
      *(pointer + 1) = BUtil_GetHiByte(value);     \
      *(pointer + 0) = BUtil_GetLoByte(value);     \
   } while(0)


/**
 * Returns a 16bit value stored in big endian format
 * in a uint8 array
 *
 * Note: Using this macro you need to suppress PRQA Message 0489 because of pointer
 * arithmetic which is not compliant to MISRA 17.4
 */
#define BUtil_Put16BitBigEndian(pointer, value) \
   do {                                         \
      *(pointer + 0) = BUtil_GetHiByte(value);  \
      *(pointer + 1) = BUtil_GetLoByte(value);  \
   } while(0)

/* PRQA L:PutGet16Bit */
#endif /* BUTIL_BYTEMASK_H_ */
