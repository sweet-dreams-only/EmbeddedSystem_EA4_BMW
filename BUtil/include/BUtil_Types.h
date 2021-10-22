/**
*  \file
*
*  \brief       BMW SWC BUtil
*
*  This file contains the data types used by BUtil.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2016
*
*  \version     5.0.3
*
*/

#ifndef BUTIL_TYPES_H_
#define BUTIL_TYPES_H_

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/

#include "BUtil/PlatformTypes.h"         /* Standard Types */
#include "BUtil_Version.h"              /* Own version */

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!BUtil_CHECK_VERSION(5,0,3))
#error "Version of BUtil_Types.h does not match the version of the module!"
#endif


#define BUTIL_SIZEOF_OF_ADDRESS_PARAM                                           \
                (BUTIL_ADDRESS_FORMAT_IDENTIFIER)
#define BUTIL_SIZEOF_OF_LENGTH_PARAM                                            \
                (BUTIL_LENGTH_FORMAT_IDENTIFIER >> 0x04u)
#define BUTIL_SIZEOF_OF_ADDRESS_AND_LENGTH_PARAMS                               \
                (BUTIL_SIZEOF_OF_ADDRESS_PARAM + BUTIL_SIZEOF_OF_LENGTH_PARAM)

/*------------------------------------------------------------------------------
                      Data Types
------------------------------------------------------------------------------*/

/**
 * Defines the format identifiers for address, length and address and length format.
 *
 * \remark According to FP5_5871 the ECUs shall only support one valid addess and
 *         lengh format identifier
 */
typedef enum {
   BUTIL_ADDRESS_FORMAT_IDENTIFIER = 0x04u,
   BUTIL_LENGTH_FORMAT_IDENTIFIER  = 0x40u,
   BUTIL_ADDRESS_AND_LENGTH_FORMAT_IDENTIFIER = BUTIL_ADDRESS_FORMAT_IDENTIFIER | BUTIL_LENGTH_FORMAT_IDENTIFIER
} BUtil_FormatIdentifier;

/**
 * \brief Type to represent unsigned 64bit values
 */
typedef struct
{
   uint32 hi;
   uint32 lo;
} BUtilUint64;


/*------------------------------------------------------------------------------
                      Global Function Declarations
------------------------------------------------------------------------------*/

#endif /* BUTIL_TYPES_H_ */

/*--- End of file ------------------------------------------------------------*/
