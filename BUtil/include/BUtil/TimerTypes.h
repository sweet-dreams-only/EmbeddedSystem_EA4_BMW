/**
 *  \file
 *
 *  \brief       BMW Timer Types
 *
 *  This file contains the platform specific types to be used by
 *  generic (platform independent) modules.
 *
 *  \project     BMW Platform Software
 *
 *  \copyright   BMW AG 2016 - 2017
 *
 *  \version     5.0.3
 *
*/

#ifndef BUTIL_TIMERTYPES_H_
#define BUTIL_TIMERTYPES_H_

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/

#include "BUtil_Version.h"
#include "BUtil/PlatformTypes.h"


/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!BUtil_CHECK_VERSION(5,0,3))
#error "Version of TimerTypes.h does not match the version of the module!"
#endif


typedef uint8 TimerHandleType;
#define TIMER_HANDLE_TYPE_INVALID 0xFFu

/*------------------------------------------------------------------------------
                      Data Types
------------------------------------------------------------------------------*/
/**
 * Callback type for timeout notifications
 */
typedef void (* CallbackFunctionType)(void* context);


/*------------------------------------------------------------------------------
                      Global Function Declarations
------------------------------------------------------------------------------*/

#endif /* BUTIL_TIMERTYPES_H_ */

/*--- End of file ------------------------------------------------------------*/
