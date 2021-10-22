/**
 * \file
 *
 * \brief       BUtil Algorithms.
 *
 * \project     BMW Platform Software
 *
 * \copyright   BMW AG 2016 - 2017
 *
 * \version     5.0.3
 *
 */

#ifndef BPS_BUTIL_ALGORITHM_H
#define BPS_BUTIL_ALGORITHM_H

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "BUtil_Version.h"


/*------------------------------------------------------------------------------
                      Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!BUtil_CHECK_VERSION(5,0,3))
#error "Version of BUtil_Algorithm.h does not match the version of the module!"
#endif


/**
 * Returns the maximum value of a and b
 */
#define BUtil_MAX(a,b) (((a)>(b))?(a):(b)) /* PRQA S 3453 *//* MISRA 19.7: Well proven macro, type independent */

/**
 * Returns the minimum value of a and b
 */
#define BUtil_MIN(a,b) (((a)<(b))?(a):(b)) /* PRQA S 3453 *//* MISRA 19.7: Well proven macro, type independent */

#endif /* BPS_BUTIL_ALGORITHM_H */
