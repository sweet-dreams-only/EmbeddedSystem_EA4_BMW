/**
*  \file
*
*  \brief       BMW SWC SysTime
*
*  This file is the generated version header file of the classic adapter
*  of the SysTime module for usage in the BMW AUTOSAR Core.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.0.3
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
*  GENERATION TIME : 2018-07-30 19:57:44.031491
*
------------------------------------------------------------------------------*/

#ifndef SYSTIMECLASSIC_VERSION_H
#define SYSTIMECLASSIC_VERSION_H


/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "SysTime_Version.h"     /* generic version header file                */

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/**
 * \brief SysTime header major version
 */
#define SysTimeClassic_MAJOR_VERSION        (5u)

/**
 * \brief SysTime header minor version
 */
#define SysTimeClassic_MINOR_VERSION        (0u)

/**
 * \brief SysTime header patch version
 */
#define SysTimeClassic_PATCH_VERSION        (3u)


/*
   MISRA-C:2004 Rule 19.7: this macro is only used in preprocessor directive, no function possible
*/
/* PRQA S 3453 5 */
/* Version check macro for adapter part */
#define SysTimeClassic_CHECK_VERSION(major,minor,patch) \
 (((major) == SysTimeClassic_MAJOR_VERSION) && \
  ((minor) == SysTimeClassic_MINOR_VERSION) && \
  ((patch) == SysTimeClassic_PATCH_VERSION))

/*
   MISRA-C:2004 Rule 19.7: this macro is only used in preprocessor directive, no function possible
*/
/* PRQA S 3453 4 */
/* Version check macro for generic part */
#define SysTimeGeneric_CHECK_VERSION(major,minor) \
 (((major) == SysTime_MAJOR_VERSION) && \
  ((minor) == SysTime_MINOR_VERSION))


/* check version of generic part */
#if (!SysTimeGeneric_CHECK_VERSION(5,0))
   #error "Version of SysTime classic adapter is incompatible to the generic module version!"
#endif
#endif /* SYSTIMECLASSIC_VERSION_H */


