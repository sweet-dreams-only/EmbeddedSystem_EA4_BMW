/*----------------------------------------------------------------------------*/
/**
*  \file
*
*  \brief       Darh Version
*
*  Version Check for Darh Module
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2016
*
*  \version     5.1.0
*
*  \remarks     -
*
*/
/*----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
*
*  THIS FILE WAS GENERATED. DO NOT MODIFY!
*
*  GENERATOR       : BMW PAGe 1.1.0
*
*  GENERATION TIME : 2018-07-30 19:57:39.592047
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

#ifndef DARH_VERSION_H
#define DARH_VERSION_H

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/**
 * \brief ModuleName header major version
 */
#define Darh_MAJOR_VERSION        (5u)

/**
 * \brief ModuleName header minor version
 */
#define Darh_MINOR_VERSION        (1u)

/**
 * \brief ModuleName header patch version
 */
#define Darh_PATCH_VERSION        (0u)

/* PRQA S 3453 2 */
#define Darh_CHECK_VERSION(major,minor,patch) \
 (((major) == Darh_MAJOR_VERSION) && ((minor) == Darh_MINOR_VERSION) && ((patch) == Darh_PATCH_VERSION))

#endif /* DARH_VERSION_H */
