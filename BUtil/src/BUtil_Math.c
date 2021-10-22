/**
 *  \file
 *
 *  \brief       Mathematical operations on 64 bit numbers
 *
 *  This file contains the implementation for mathematical operations for usage
 *  in the BMW AUTOSAR Core.
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
/*
 * Violation of MISRA rule 19.1. Reason: including BUtil_MemMap.h is necessary throughout
 * the file according to memory abstraction, see PRQA: 5087
 */

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/

#include "BUtil_Math.h"           /* Own header file        */
#include "BUtil_Version.h"


/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!BUtil_CHECK_VERSION(5,0,3))
#error "Version of BUtil_Math.c does not match the version of the module!"
#endif

/**
 * \brief Biggest possible value fitting in a 32-bit type
 */
#define BUTIL_BIGGEST_32BITVAL  ((uint32) 0xFFFFFFFFu)

/**
 * Number of bits in an uint32
 */
#define BUTIL_32BIT 32u


/*------------------------------------------------------------------------------
                      Global Functions
------------------------------------------------------------------------------*/

#define BUtil_START_SEC_CODE
#include "BUtil_MemMap.h" /* PRQA S 5087 */

/**
 * Shifts the given \p Value by \p Shift positions to left. The shifted result is returned in the out parameter \p Result.
 *
 * \param[in] Value The value which shall be shifted
 * \param[in] Shift The number of positions the value shall be shifted
 * \param[out] Result The 64-bit result of the shifting operation
 */
void BUtil_Math_LeftShift32To64(
   uint32 Value,
   uint8 Shift,
   BUtilUint64* const Result)
{
   if (0 == Shift)
   {
      Result->hi = 0;
      Result->lo = Value;
   }
   else if (BUTIL_32BIT > Shift)
   {
      Result->hi = (Value >> (BUTIL_32BIT - Shift));
      Result->lo = (Value << Shift);
   }
   else
   {
      Result->hi = (Value << (Shift - BUTIL_32BIT));
      Result->lo = 0;
   }
}

/**
 * Shifts the given \p Value by \p Shift positions to right. The shifted result is returned.
 * If the shifted result does not fit into an uint32, #BUTIL_BIGGEST_32BITVAL is returned.
 *
 * \param[in] Shift The number of positions the value shall be shifted
 * \param[in] Value The 64-bit value which shall be shifted
 *
 * \return Result of the shift operation or #BUTIL_BIGGEST_32BITVAL on overflow
 */
uint32 BUtil_Math_RightShift64To32(
    const BUtilUint64* const Value,
    uint8 Shift)
{
   uint32 Result = BUTIL_BIGGEST_32BITVAL;

   if (0 == Shift)
   {
      if (0 == Value->hi)
      {
         Result = Value->lo;
      }
   }
   else if (BUTIL_32BIT > Shift)
   {
      if (0 == (Value->hi >> Shift))
      {
         Result = (Value->lo >> Shift) | (Value->hi << (BUTIL_32BIT - Shift));
      }
   }
   else
   {
      Result = (Value->hi >> (Shift - BUTIL_32BIT));
   }

   return Result;
}


/**
 * First multiplies the \p Multiplicand and \p Multiplicator and then divides this by the \p Divisor. The multiplication is
 * done with a 64bit temporary type to assure the product of the multiplication has no overflow. In case the result
 * of the result of the division is bigger than 32bit the highest 32bit value is returned.
 *
 * \param[in] Multiplicand The multiplicand of the multiplication
 * \param[in] Multiplicator The multiplicator of the multiplication
 * \param[in] Divisor The divisor for the division with the product of the multiplication
 *
 * \return Result of the multiplication and division. In case the result is >32bit the biggest 32bit value is returned
 */
uint32 BUtil_Math_MultiplyNDivide(uint32 Multiplicand, uint32 Multiplicator, uint32 Divisor)
{
   uint32 result = 0;

   if (Divisor != 0)
   {
      BUtilUint64 product;
      BUtil_Math_Multiplication32To64(Multiplicand, Multiplicator, &product);
      result = BUtil_Math_Divide64by32(&product, Divisor);
   }

   return result;
}

/**
 * Multiplies the \p Multiplicand and \p Multiplicator and returns the \p Product as a 64bit value.
 *
 * \param[in] Multiplicand The multiplicand of the multiplication
 * \param[in] Multiplicator The multiplicator of the multiplication
 * \param[out] Product The pointer to the result
 */
void BUtil_Math_Multiplication32To64(
   uint32 Multiplicand,
   uint32 Multiplicator,
   BUtilUint64* const  Product)
{
   uint16 multiplicandLo = (uint16) (Multiplicand & 0x0000FFFFu);
   uint16 multiplicandHi = (uint16) (Multiplicand >> 16);
   uint16 multiplicatorLo = (uint16) (Multiplicator & 0x0000FFFFu);
   uint16 multiplicatorHi = (uint16) (Multiplicator >> 16);

   /* a * b = AH * BH * 2^32 + (AH * BL + AL * BH) * 2^16 + AL * BL */
   uint32 high = ((uint32) multiplicandHi) * multiplicatorHi; /* AH * BH */
   uint32 mid2 = ((uint32) multiplicandHi) * multiplicatorLo; /* AH * BL */
   uint32 mid1 = ((uint32) multiplicandLo) * multiplicatorHi; /* AL * BH */
   uint32 low = ((uint32) multiplicandLo) * multiplicatorLo;  /* AL * BL */
   uint32 temp = 0;

   /* in case temp is smaller than mid1 - we had an overflow and must set the carry bit to high */

   temp = mid1 + mid2;
   if (temp < mid1)
   {
      high += ((uint32)1u) << 16; /* add the carry bit to the hi-lo-byte */
   }
   mid1 = temp;

   /* truncate the bits which are not relevant for the upcoming additions */
   mid2 = mid1 >> 16;
   mid1 = mid1 << 16;

   /* detect if we have another overflow and need to add the carry bit */
   temp = low + mid1;
   if (temp < low)
   {
      high++; /* add the carry bit to the lo-lo-byte */
   }

   Product->hi = high + mid2;
   Product->lo = low + mid1;
}

/**
 * Divides the \p Dividend by the \p Divisor and returns the quotient as a 64bit value. In case the quotient is bigger than
 * 32bit the maximum 32bit value is returned.
 *
 * \param[in] Dividend The dividend of the division
 * \param[in] Divisor The divisor of the division
 *
 * \return Result of the division as 32bit value. In case the quotient is bigger than 32bit the maximum 32bit value
 * is returned.
 */
uint32 BUtil_Math_Divide64by32(
    const BUtilUint64* const Dividend,
   uint32 Divisor)
{
   uint32 quotient;

   /* prevent division by 0 and also overflow */
   if (Dividend->hi >= Divisor)
   {
      quotient = BUTIL_BIGGEST_32BITVAL;
   }
   /* high bytes are not used - in this case a fast simple division with 32bit values can be made */
   else if (Dividend->hi == 0)
   {
      quotient = Dividend->lo / Divisor;
   }
   else
   {
      uint32 loopCnt;
      uint32 rest = Dividend->hi;
      uint32 shift = Dividend->lo;
      boolean multiply = FALSE;

      if (Divisor >= (BUTIL_BIGGEST_32BITVAL / 2))
      {
         Divisor /= 2;
         multiply = TRUE;
      }

      quotient = 0;

      /*
       * calculate quotient bitwise, each bit in its own step, the arithmetic is done by long division algorithm
       *  351 : 4 = 87
       *  32
       *  --
       *   31
       *   28
       *   --
       *    3 (Rest)
       */
      for (loopCnt = 0; loopCnt < 32; ++loopCnt)
      {
         quotient = quotient << 1;
         rest = rest << 1;
         rest |= shift >> 31;

         if (rest >= Divisor)
         {
            rest -= Divisor;
            quotient |= 1;
         }

         shift = shift << 1;
      }
      if (multiply == TRUE)
      {
         quotient /= 2;
      }
   }

   return quotient;
}

#define BUtil_STOP_SEC_CODE
#include "BUtil_MemMap.h" /* PRQA S 5087 */

/*--- End of file ------------------------------------------------------------*/
