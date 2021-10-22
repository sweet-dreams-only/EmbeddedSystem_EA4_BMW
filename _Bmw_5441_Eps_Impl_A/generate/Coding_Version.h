/**
 * \file
 *
 * \brief       Coding Version Check
 *
 * \project     BMW Platform Software
 *
 * \copyright   BMW AG 2016 - 2017
 *
 * \version     5.2.1
 *
 */

/*------------------------------------------------------------------------------
*
*  THIS FILE WAS GENERATED. DO NOT MODIFY!
*
*  GENERATOR       : BMW PAGe 1.1.0
*
*  GENERATION TIME : 2018-07-30 19:57:41.225210
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


#ifndef CODING_VERSION_H
#define CODING_VERSION_H

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/**
 * \brief Coding header major version
 */
#define Coding_MAJOR_VERSION        (5u)

/**
 * \brief Coding header minor version
 */
#define Coding_MINOR_VERSION        (2u)

/**
 * \brief Coding header patch version
 */
#define Coding_PATCH_VERSION        (1u)

/* PRQA S 3453 2 */
#define Coding_CHECK_VERSION(major,minor,patch) \
 (((major) == Coding_MAJOR_VERSION) && ((minor) == Coding_MINOR_VERSION) && ((patch) == Coding_PATCH_VERSION))

#endif /* CODING_VERSION_H */
