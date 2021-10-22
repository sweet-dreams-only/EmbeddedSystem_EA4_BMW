/**
 * \file
 *
 * \brief       BUtil Version Information
 *
 * This file is a generated version header file
 * for usage in the BMW AUTOSAR Core.
 *
 * \project     BMW Platform Software
 *
 * \copyright   BMW AG 2016 - 2017
 *
 * \version     5.1.1
 *
 */

/*------------------------------------------------------------------------------
*
*  THIS FILE WAS GENERATED. DO NOT MODIFY!
*
*  GENERATOR       : %{= generation_tool() }% %{= generation_version_info() }%
*
*  GENERATION TIME : %{= generation_timestamp() }%
*
------------------------------------------------------------------------------*/

#ifndef BUTILCLASSIC_VERSION_H
#define BUTILCLASSIC_VERSION_H

#include "BUtil_Version.h"

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/**
 * \brief BUtil header major version
 */
#define BUtilClassic_MAJOR_VERSION        (5u)

/**
 * \brief BUtil header minor version
 */
#define BUtilClassic_MINOR_VERSION        (1u)

/**
 * \brief BUtil header patch version
 */
#define BUtilClassic_PATCH_VERSION        (1u)


/* PRQA S 3453 2 */ /* Macro used for precompile version check */
#define BUtilClassic_CHECK_VERSION(major,minor,patch) \
 (((major) == BUtilClassic_MAJOR_VERSION) && ((minor) == BUtilClassic_MINOR_VERSION) && ((patch) == BUtilClassic_PATCH_VERSION))


/* Version check macro for generic part */
#define BUtilGeneric_CHECK_VERSION(major,minor) \
 (((major) == BUtil_MAJOR_VERSION) && \
  ((minor) == BUtil_MINOR_VERSION))

/* check version of the generic part */
#if (!BUtilGeneric_CHECK_VERSION(5,0))
   #error "Version of Classic adapter is incompatible to the generic module version!"
#endif

#endif /* BUTILCLASSIC_VERSION_H */

/*--- End of file ------------------------------------------------------------*/
