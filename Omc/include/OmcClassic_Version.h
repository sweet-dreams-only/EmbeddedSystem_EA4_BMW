/**
*  \file
*
*  \brief       Omc Classic Adapter Version
*
*  Version Check for Omc module
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.2.0
*
*/

/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/
/*
 * Violation of MISRA-C:2004 Rule 19.7:
 * Reason: this macro is only used in preprocessor directive,
 * no function possible. See PRQA 3453
 */


#ifndef OMCCLASSIC_VERSION_H
#define OMCCLASSIC_VERSION_H

/*------------------------------------------------------------------------------
                      Includes
------------------------------------------------------------------------------*/
#include "Omc_Version.h"

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/**
 * \brief Omc header major version
 */
#define OmcClassic_MAJOR_VERSION        (5u)

/**
 * \brief Omc header minor version
 */
#define OmcClassic_MINOR_VERSION        (2u)

/**
 * \brief Omc header patch version
 */
#define OmcClassic_PATCH_VERSION        (0u)

/* Version check macro for adapter part */
/* PRQA S 3453 2 */
#define OmcClassic_CHECK_VERSION(major,minor,patch) \
 (((major) == OmcClassic_MAJOR_VERSION) && \
  ((minor) == OmcClassic_MINOR_VERSION) && \
  ((patch) == OmcClassic_PATCH_VERSION))


/* Version check macro for generic part */
/* PRQA S 3453 2 */
#define OmcGeneric_CHECK_VERSION(major,minor) \
 (((major) == Omc_MAJOR_VERSION) && \
  ((minor) == Omc_MINOR_VERSION))

/* check version of generic part */
#if (!OmcGeneric_CHECK_VERSION(5,1))
   #error "Version of Omc classic adapter is incompatible to the generic module version!"
#endif

#endif /* OMCCLASSIC_VERSION_H */
