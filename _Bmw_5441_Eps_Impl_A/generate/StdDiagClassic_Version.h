/**
*  \file
*
*  \brief       BMW SWC StdDiag
*
*  This file is the generated version header file of the StdDiag module
*  for usage in the BMW AUTOSAR Core.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.4.0
*
*  \remarks     --
*
*/

/*------------------------------------------------------------------------------
*
*  THIS FILE WAS GENERATED. DO NOT MODIFY!
*
*  GENERATOR       : BMW PAGe 1.1.0
*
*  GENERATION TIME : 2018-07-30 19:57:43.186406
*
------------------------------------------------------------------------------*/

#ifndef StdDiagClassic_VERSION_H
#define StdDiagClassic_VERSION_H


/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "StdDiag_Version.h"     /* generic version header file                */

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/**
 * \brief StdDiag header major version
 */
#define StdDiagClassic_MAJOR_VERSION        (5u)

/**
 * \brief StdDiag header minor version
 */
#define StdDiagClassic_MINOR_VERSION        (4u)

/**
 * \brief StdDiag header patch version
 */
#define StdDiagClassic_PATCH_VERSION        (0u)


/*
   MISRA-C:2004 Rule 19.7: this macro is only used in preprocessor directive, no function possible
*/
/* PRQA S 3453 5 */
/* Version check macro for adapter part */
#define StdDiagClassic_CHECK_VERSION(major,minor,patch) \
 (((major) == StdDiagClassic_MAJOR_VERSION) && \
  ((minor) == StdDiagClassic_MINOR_VERSION) && \
  ((patch) == StdDiagClassic_PATCH_VERSION))


/*
   MISRA-C:2004 Rule 19.7: this macro is only used in preprocessor directive, no function possible
*/
/* PRQA S 3453 4 */
/* Version check macro for generic part */
#define StdDiagGeneric_CHECK_VERSION(major,minor) \
 (((major) == StdDiag_MAJOR_VERSION) && \
  ((minor) == StdDiag_MINOR_VERSION))


/* check version of generic part */
#if (!StdDiagGeneric_CHECK_VERSION(5,3))
   #error "Version of StdDiag classic adapter is incompatible to the generic module version!"
#endif

#endif /* StdDiagClassic_VERSION_H */


