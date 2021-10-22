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

#ifndef BUTIL_MATH_H
#define BUTIL_MATH_H

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/

#include "BUtil_Version.h"          /* Version header file */
#include "BUtil_Types.h"


/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!BUtil_CHECK_VERSION(5,0,3))
#error "Version of BUtil_Math.h does not match the version of the module!"
#endif


/*------------------------------------------------------------------------------
                      Data Types
------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------
                      Global Variables
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Global Constants
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Global Function Declarations
------------------------------------------------------------------------------*/

extern void BUtil_Math_LeftShift32To64(
   uint32 Value,
   uint8 Shift,
   BUtilUint64* const Result);

extern uint32 BUtil_Math_RightShift64To32(
   const BUtilUint64* const Value,
   uint8 Shift);

extern uint32 BUtil_Math_MultiplyNDivide(uint32 Multiplicand, uint32 Multiplicator, uint32 Divisor);

extern void BUtil_Math_Multiplication32To64(
   uint32 Multiplicand,
   uint32 Multiplicator,
   BUtilUint64* const  Product);

extern uint32 BUtil_Math_Divide64by32(
   const BUtilUint64* const Dividend,
   uint32 Divisor);

#endif /* BUTIL_MATH_H */

/*--- End of file ------------------------------------------------------------*/
