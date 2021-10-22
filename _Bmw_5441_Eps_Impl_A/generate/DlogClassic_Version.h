/*----------------------------------------------------------------------------*/
/**
*  \file
*
*  \brief       Dlog Version Information
*
*  This file is a generated version header file
*  for usage in the BMW AUTOSAR Core.
*
*  \project     BMW AUTOSAR Core
*
*  \par         To be changed by user:
*               [yes/no]
*
*  \copyright   BMW AG 2015 - 2016
*
*  \version     5.3.1
*
*  \remarks     ---
*
*/
/*----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
*
*  THIS FILE WAS GENERATED. DO NOT MODIFY!
*
*  GENERATOR       : BMW PAGe 1.1.0
*
*  GENERATION TIME : 2018-07-30 19:57:39.518040
*
------------------------------------------------------------------------------*/

#ifndef DLOGCLASSIC_VERSION_H
#define DLOGCLASSIC_VERSION_H

#include "Dlog_Version.h"

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/**
 * \brief Dlog header major version
 */
#define DlogClassic_MAJOR_VERSION        (5u)

/**
 * \brief Dlog header minor version
 */
#define DlogClassic_MINOR_VERSION        (3u)

/**
 * \brief Dlog header patch version
 */
#define DlogClassic_PATCH_VERSION        (1u)


/* PRQA S 3453 2 */ /* Macro used for precompile version check */
#define DlogClassic_CHECK_VERSION(major,minor,patch) \
 (((major) == DlogClassic_MAJOR_VERSION) && ((minor) == DlogClassic_MINOR_VERSION) && ((patch) == DlogClassic_PATCH_VERSION))


/* Version check macro for generic part */
#define DlogGeneric_CHECK_VERSION(major,minor) \
 (((major) == Dlog_MAJOR_VERSION) && \
  ((minor) == Dlog_MINOR_VERSION))

/* check version of the generic part */
#if (!DlogGeneric_CHECK_VERSION(5,1))
#error "Version of Classic adapter is incompatible to the generic module version!"
#endif


#endif /* DLOGCLASSIC_VERSION_H */

/*--- End of file ------------------------------------------------------------*/
