/**
*  \file
*
*  \brief       BMW SWC RmhClassic
*
*  This file is a sample for the memory mapping header file of
*  the BMW AUTOSAR Core module "RmhClassic".
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.0.0
*
*  \remarks     This file contains all memory mapping macros of the
*               module "RmhClassic".
*
*/

/*------------------------------------------------------------------------------

/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/
/*
 * MISRA-C:2004 Deviation List:
 *
 * Deviated Rule: 19.6 (required)
 * #undef shall not be used.
 *
 * Reason:
 * The compiler directive undef is required within memory mapping header files.
 *
 * Deviated Rule: 19.15 (required)
 * Precautions shall be taken in order to prevent the contents of a header file
 * being included twice.
 *
 * Reason:
 * Memory mapping files shall not be protected against multiple inclusions.
 */
/* PRQA S 0841 EOF */
/* PRQA S 0883 EOF */

// Rmh_START_SEC_CODE
#ifdef Rmh_START_SEC_CODE
#undef Rmh_START_SEC_CODE
#define START_SEC_CODE
#include "MemMap.h"
#endif

#ifdef Rmh_STOP_SEC_CODE
#undef Rmh_STOP_SEC_CODE
#define STOP_SEC_CODE
#include "MemMap.h"
#endif
// Rmh_START_SEC_CONST_UNSPECIFIED
#ifdef Rmh_START_SEC_CONST_UNSPECIFIED
#undef Rmh_START_SEC_CONST_UNSPECIFIED
#endif

#ifdef Rmh_STOP_SEC_CONST_UNSPECIFIED
#undef Rmh_STOP_SEC_CONST_UNSPECIFIED
#endif