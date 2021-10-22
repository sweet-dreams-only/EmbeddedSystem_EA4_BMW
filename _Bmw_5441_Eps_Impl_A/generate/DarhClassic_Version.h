/**
*  \file
*
*  \brief       Darh Classic Version
*
*  This file contains the implementation of the checks of the Darh classic version.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2017
*
*  \version     5.1.0
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
*  GENERATION TIME : 2018-07-30 19:57:39.329021
*
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/
/*
 * Violation of MISRA-C:2004 Rule 19.7:
 * Reason: this macro is only used in preprocessor directive,
 * no function possible. See PRQA 3453
 */

#ifndef DARHCLASSIC_VERSION_H
#define DARHCLASSIC_VERSION_H

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/
#include "Darh_Version.h"

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/
/**
 * \brief ModuleName header major version
 */
#define DarhClassic_MAJOR_VERSION         (5u)

/**
 * \brief ModuleName header minor version
 */
#define DarhClassic_MINOR_VERSION         (1u)

/**
 * \brief ModuleName header patch version
 */
#define DarhClassic_PATCH_VERSION         (0u)

/* PRQA S 3453 2 */
#define DarhClassic_CHECK_VERSION(major,minor,patch) \
 (((major) == DarhClassic_MAJOR_VERSION) && ((minor) == DarhClassic_MINOR_VERSION) && ((patch) == DarhClassic_PATCH_VERSION))

/* Version check macro for generic part */
#define DarhGeneric_CHECK_VERSION(major,minor) \
 (((major) == Darh_MAJOR_VERSION) && \
  ((minor) == Darh_MINOR_VERSION))

/* check version of generic part */
#if (!DarhGeneric_CHECK_VERSION(5,1))
#error "Version of Darh classic adapter is incompatible to the generic module version!"
#endif

#endif /* DARHCLASSIC_VERSION_H */
